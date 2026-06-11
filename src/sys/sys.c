#include"shinsei/minimal/sys.h"

#ifdef _SHINSEI_OS_CPP
#define this _this
extern "C"{
#endif

// [Internal] CPU pause hint
_SHINSEI_OS_INLINE static bool cPUPause()_SHINSEI_OS_NOEXCEPT{
	#if(defined(_SHINSEI_OS_GNUC)||defined(_SHINSEI_OS_CLANG))
		#if(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_X86)||defined(_SHINSEI_OS_RISCV64)||defined(_SHINSEI_OS_RISCV32))
			__asm__ volatile("pause":::"memory");
			return true;
		#elif(defined(_SHINSEI_OS_ARM64)||defined(_SHINSEI_OS_ARM)||defined(_SHINSEI_OS_S390X))
			__asm__ volatile("yield":::"memory");
			return true;
		#elif(defined(_SHINSEI_OS_POWERPC64)||defined(_SHINSEI_OS_POWERPC32))
			__asm__ volatile("or 27,27,27":::"memory");
			return true;
		#else
			__asm__ volatile("":::"memory");
			return false;
		#endif
	#elif(defined(_SHINSEI_OS_MSVC))
		#if(defined(_SHINSEI_OS_X64)||defined(_SHINSEI_OS_X86))
			_mm_pause();
			return true;
		#elif(defined(_SHINSEI_OS_ARM64)||defined(_SHINSEI_OS_ARM))
			__yield();
			return true;
		#else
			__nop();
			return false;
		#endif
	#else
		return false;
	#endif
}

// CPU pause hint
bool shinsei_cPUPause()_SHINSEI_OS_NOEXCEPT{
	return cPUPause();
}

// arena_meta_t

// [Internal, const] Check if meta is inlined
_SHINSEI_OS_INLINE static bool arn_meta_inlined(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal] Static assign
_SHINSEI_OS_INLINE static void arn_meta_asAssign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size_and_used=src->size_and_used;
	return;
}

// [Internal] Static move
_SHINSEI_OS_INLINE static void arn_meta_asMove(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl;
	this->size_and_used=src->size_and_used;
	src->ctrl=0;
	src->size_and_used=0;
	return;
}

shinsei_arena_meta_t* shinsei_arena_meta_t_con(const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_meta_t*const this=(shinsei_arena_meta_t*const)__builtin_malloc(sizeof(shinsei_arena_meta_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	this->ctrl=0;
	this->size_and_used=size|!!used;
	return this;
}

shinsei_arena_meta_t* shinsei_arena_meta_t_conAssign(const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_meta_t*const this=(shinsei_arena_meta_t*const)__builtin_malloc(sizeof(shinsei_arena_meta_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	arn_meta_asAssign(this,src);
	return this;
}

shinsei_arena_meta_t* shinsei_arena_meta_t_conMove(shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_meta_t*const this=(shinsei_arena_meta_t*const)__builtin_malloc(sizeof(shinsei_arena_meta_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	arn_meta_asMove(this,src);
	return this;
}

void shinsei_arena_meta_t_dec(shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	__builtin_free(this);
	return;
}

void shinsei_arena_meta_t_assign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	arn_meta_asAssign(this,src);
	return;
}

void shinsei_arena_meta_t_move(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	arn_meta_asMove(this,src);
	return;
}

void shinsei_arena_meta_t_attach(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=(src->ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size_and_used=src->size_and_used;
	return;
}

void shinsei_arena_meta_t_attachValue(shinsei_arena_meta_t*const restrict this,const int_fast32_t ctrl,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=(ctrl&~_SHINSEI_CTRL_INLINED)|(this->ctrl&_SHINSEI_CTRL_INLINED);
	this->size_and_used=size|!!used;
	return;
}

void shinsei_arena_meta_t_as(shinsei_arena_meta_t*const restrict this,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->size_and_used=size|!!used;
	return;
}

void shinsei_arena_meta_t_asAssign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	arn_meta_asAssign(this,src);
	return;
}

void shinsei_arena_meta_t_asMove(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	arn_meta_asMove(this,src);
	return;
}

void shinsei_arena_meta_t_inl(shinsei_arena_meta_t*const restrict this,const size_t size,const bool used)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->size_and_used=size|!!used;
	return;
}

void shinsei_arena_meta_t_inlAssign(shinsei_arena_meta_t*const restrict this,const shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size_and_used=src->size_and_used;
	return;
}

void shinsei_arena_meta_t_inlMove(shinsei_arena_meta_t*const restrict this,shinsei_arena_meta_t*const restrict src)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=src->ctrl|_SHINSEI_CTRL_INLINED;
	this->size_and_used=src->size_and_used;
	src->ctrl=0;
	src->size_and_used=0;
	return;
}

bool shinsei_arena_meta_t_inlined(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return arn_meta_inlined(this);
}

int_fast32_t shinsei_arena_meta_t_getCtrl(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

void shinsei_arena_meta_t_setCtrl(shinsei_arena_meta_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

size_t shinsei_arena_meta_t_getSize(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
}

void shinsei_arena_meta_t_setSize(shinsei_arena_meta_t*const restrict this,const size_t size)_SHINSEI_OS_NOEXCEPT{
	this->size_and_used=size|(this->size_and_used&1);
	return;
}

bool shinsei_arena_meta_t_getUsed(const shinsei_arena_meta_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->size_and_used&1;
}

void shinsei_arena_meta_t_setUsed(shinsei_arena_meta_t*const restrict this,const bool used)_SHINSEI_OS_NOEXCEPT{
	this->size_and_used=(this->size_and_used&~(size_t)1)|!!used;
	return;
}

// arena_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool arn_inlined(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* arn_data(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return (char*)((uintptr_t)&this->data*arn_inlined(this)+!arn_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Free all chained elements
_SHINSEI_OS_INLINE static void arn_freeData(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_t* cur=this->next;
	while(cur!=nullptr){
		register shinsei_arena_t* nxt=cur->next;
		if(!arn_inlined(cur)){
			__builtin_free(cur->data);
			__builtin_free(cur);
		}
		cur=nxt;
	}
	if(!arn_inlined(this)) __builtin_free(this->data);
	return;
}

// [Internal] Init arena structure
_SHINSEI_OS_INLINE static void arn_initBlock(shinsei_arena_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ref_count=0;
	this->head=0;
	this->tail=0;
	this->min_space_cap=cap;
	this->max_space_cap=cap;
	this->next=nullptr;
	this->last_part=this;
	
	register shinsei_arena_meta_t* meta=(shinsei_arena_meta_t*)arn_data(this);
	meta->ctrl=0;
	meta->size_and_used=cap; 
	return;
}

// [Internal] Allocate next part safely
_SHINSEI_OS_INLINE static shinsei_arena_t* arn_expandPart(shinsei_arena_t*const restrict this,const size_t target_sz)_SHINSEI_OS_NOEXCEPT{
	register size_t next_cap=this->last_part->cap;
	while(next_cap<target_sz){
		register size_t proposed=next_cap<<1;
		if(__builtin_expect(proposed<next_cap,0)) proposed=target_sz; 
		next_cap=proposed;
	}
	register shinsei_arena_t*const new_part=(shinsei_arena_t*)__builtin_malloc(sizeof(shinsei_arena_t));
	if(__builtin_expect(new_part==nullptr,0)) return nullptr;
	new_part->ctrl=0;
	new_part->cap=next_cap;
	new_part->data=(char*)__builtin_malloc(next_cap);
	if(__builtin_expect(new_part->data==nullptr,0)){
		__builtin_free(new_part);
		return nullptr;
	}
	arn_initBlock(new_part,next_cap);
	this->last_part->next=new_part;
	this->last_part=new_part;
	return new_part;
}

// Default constructor
shinsei_arena_t* shinsei_arena_t_con(const size_t cap)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_t*const this=(shinsei_arena_t*const)__builtin_malloc(sizeof(shinsei_arena_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!shinsei_arena_t_as(this,cap),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Free all chained elements
void shinsei_arena_t_freeData(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	arn_freeData(this);
	return;
}

// Destructor
void shinsei_arena_t_dec(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	arn_freeData(this);
	__builtin_free(this);
	return;
}

// Static Constructor
bool shinsei_arena_t_as(shinsei_arena_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->cap=cap;
	this->data=(char*)__builtin_malloc(cap);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	arn_initBlock(this,cap);
	return true;
}

// Inline Constructor
void shinsei_arena_t_inl(shinsei_arena_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->cap=cap;
	arn_initBlock(this,cap);
	return;
}

// Allocate from First available spot
void* shinsei_arena_t_allocFront(shinsei_arena_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT{
	register const size_t real_cost=(sizeof(shinsei_arena_meta_t)+needed_cap+(shinsei_arena_t_BYTE_ALIGNMENT-1))&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	register shinsei_arena_t* part=this;
	register shinsei_arena_meta_t* meta=nullptr;
	register size_t offset=0;
	register size_t m_size=0;
	
	meta=(shinsei_arena_meta_t*)arn_data(this);
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	if(!(meta->size_and_used&1)&&m_size>=real_cost){
		goto allocate_block;
	}

	while(part!=nullptr){
		offset=0;
		register char*const buffer=arn_data(part);
		while(offset<part->cap){
			meta=(shinsei_arena_meta_t*)(buffer+offset);
			m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
			if(!(meta->size_and_used&1)&&m_size>=real_cost) goto allocate_block;
			offset+=m_size;
		}
		part=part->next;
	}
	
	if(arn_inlined(this)) return nullptr;
	part=arn_expandPart(this,real_cost);
	if(__builtin_expect(part==nullptr,0)) return nullptr;
	meta=(shinsei_arena_meta_t*)arn_data(part);
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	offset=0;
	
allocate_block:
	if(m_size>=real_cost+sizeof(shinsei_arena_meta_t)+shinsei_arena_t_BYTE_ALIGNMENT){
		register shinsei_arena_meta_t*const next_meta=(shinsei_arena_meta_t*)((char*)meta+real_cost);
		next_meta->ctrl=0;
		next_meta->size_and_used=m_size-real_cost;
		meta->size_and_used=real_cost|1;
	} else {
		meta->size_and_used|=1;
	}
	
	++this->ref_count;
	if(this->ref_count==1){
		this->head=offset;
		this->tail=offset;
	}
	return (void*)((char*)meta+sizeof(shinsei_arena_meta_t));
}

// Allocate from Last available spot
void* shinsei_arena_t_allocBack(shinsei_arena_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT{
	register const size_t real_cost=(sizeof(shinsei_arena_meta_t)+needed_cap+(shinsei_arena_t_BYTE_ALIGNMENT-1))&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	register shinsei_arena_t* part=this->last_part;
	register shinsei_arena_meta_t* meta=nullptr;
	register shinsei_arena_meta_t* last_valid=nullptr;
	register size_t offset=0,last_offset=0;
	register size_t m_size=0;
	
	if(this->ref_count){
		shinsei_arena_meta_t* last_used=(shinsei_arena_meta_t*)(arn_data(part)+this->tail);
		size_t after_offset=this->tail+(last_used->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
		if(after_offset<part->cap){
			meta=(shinsei_arena_meta_t*)(arn_data(part)+after_offset);
			m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
			if(!(meta->size_and_used&1)&&m_size>=real_cost){
				last_valid=meta;
				last_offset=after_offset;
			}
		}
	}
	else{
		meta=(shinsei_arena_meta_t*)arn_data(part);
		m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
		if(!(meta->size_and_used&1)&&m_size>=real_cost){
			last_valid=meta;
			last_offset=0;
		}
	}
	
	if(!last_valid){
		part=this;
		register shinsei_arena_t* found_part=nullptr;
		while(part!=nullptr){
			offset=0;
			register char*const buffer=arn_data(part);
			while(offset<part->cap){
				meta=(shinsei_arena_meta_t*)(buffer+offset);
				m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
				if(!(meta->size_and_used&1)&&m_size>=real_cost){
					last_valid=meta;
					last_offset=offset;
					found_part=part;
				}
				offset+=m_size;
			}
			part=part->next;
		}
		if(last_valid) part=found_part;
	}
	
	if(last_valid) meta=last_valid;
	else{
		if(arn_inlined(this)) return nullptr;
		part=arn_expandPart(this,real_cost);
		if(__builtin_expect(part==nullptr,0)) return nullptr;
		meta=(shinsei_arena_meta_t*)arn_data(part);
		last_offset=0;
	}
	
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	if(m_size>=real_cost+sizeof(shinsei_arena_meta_t)+shinsei_arena_t_BYTE_ALIGNMENT){
		register shinsei_arena_meta_t*const next_meta=(shinsei_arena_meta_t*)((char*)meta+m_size-real_cost);
		next_meta->ctrl=0;
		next_meta->size_and_used=real_cost|1; 
		meta->size_and_used=m_size-real_cost; 
		meta=next_meta; 
		last_offset+=m_size-real_cost;
	}
	else{
		meta->size_and_used|=1;
	}
	
	++this->ref_count;
	if(this->ref_count==1) this->head=last_offset;
	if(part==this->last_part) this->tail=last_offset;
	
	return (void*)((char*)meta+sizeof(shinsei_arena_meta_t));
}

// Free Front
void shinsei_arena_t_freeFront(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!this->ref_count,0)) return;
	
	register shinsei_arena_t* part=this;
	register char* buffer;
	register shinsei_arena_meta_t* prev=nullptr;
	register shinsei_arena_meta_t* meta=nullptr;
	register size_t offset=0;

	buffer=arn_data(part);
	meta=(shinsei_arena_meta_t*)(buffer+this->head);
	if(meta->size_and_used & 1){
		offset=this->head;
		if(this->head>0){
			shinsei_arena_meta_t*const first=(shinsei_arena_meta_t*)buffer;
			if (!(first->size_and_used&1)&&(first->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1))==this->head) prev=first;
		}
		goto do_free;
	}
	
	while(part!=nullptr){
		offset=0;
		buffer=arn_data(part);
		prev=nullptr;
		while(offset<part->cap){
			meta=(shinsei_arena_meta_t*)(buffer+offset);
			if(meta->size_and_used&1) goto do_free;
			prev=meta;
			offset+=(meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
		}
		part=part->next;
	}
	return;

do_free:
	meta->size_and_used&=~(size_t)1;
	--this->ref_count;
	
	if(prev&&!(prev->size_and_used&1)){
		prev->size_and_used+=(meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
		meta=prev;
		offset=(size_t)((char*)meta-buffer);
	}
	register size_t m_size=meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
	register size_t next_off=offset+m_size;
	if(next_off<part->cap){
		register shinsei_arena_meta_t* next=(shinsei_arena_meta_t*)(buffer+next_off);
		if(!(next->size_and_used&1)) meta->size_and_used+=(next->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
	}
	
	if(m_size==part->cap){
		if(part==this&&this->next!=nullptr&&!arn_inlined(this)){
			shinsei_arena_t* next_part=this->next;
			__builtin_free(this->data); 
			this->cap=next_part->cap;
			this->data=next_part->data; 
			this->next=next_part->next;
			if(this->last_part==next_part) this->last_part=this;
			__builtin_free(next_part);
			this->head=0;
		}
		else if(part!=this){
			shinsei_arena_t* p=this;
			while(p->next!=part&&p->next!=nullptr) p=p->next;
			if(p->next==part){
				p->next=part->next;
				if(this->last_part==part){
					this->last_part=p;
					if(this->ref_count>0){
						size_t scan_off=0,new_tail=0;
						char* buf=arn_data(p);
						while(scan_off<p->cap){
							shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buf+scan_off);
							if(m->size_and_used&1) new_tail=scan_off;
							scan_off+=(m->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
						}
						this->tail=new_tail;
					}else{
						this->tail=0;
						this->head=0;
					}
				}
				__builtin_free(part->data);
				__builtin_free(part);
			}
		}
	}
	else if(part==this&&this->ref_count&&next_off<part->cap){
		this->head=next_off;
	}
}

// Free Back
void shinsei_arena_t_freeBack(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!this->ref_count,0)) return;
	
	register shinsei_arena_t* part=this->last_part;
	register shinsei_arena_t* target_part=nullptr;
	register shinsei_arena_meta_t* target_meta=nullptr;
	register shinsei_arena_meta_t* target_prev=nullptr;
	register size_t offset=0;
	
	register char* buffer=arn_data(part);
	register shinsei_arena_meta_t* prev=nullptr;
	while(offset<part->cap){
		register shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buffer+offset);
		if(offset==this->tail && (m->size_and_used & 1)){
			target_part=part;
			target_meta=m;
			target_prev=prev;
			break;
		}
		prev=m;
		offset+=(m->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
	}
	
	if(!target_meta){
		part=this;
		while(part!=nullptr){
			offset=0;
			buffer=arn_data(part);
			prev=nullptr;
			while(offset<part->cap){
				register shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buffer+offset);
				if(m->size_and_used&1){
					target_part=part;
					target_meta=m;
					target_prev=prev;
				}
				prev=m;
				offset+=(m->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
			}
			part=part->next;
		}
	}
	
	if(target_meta){
		target_meta->size_and_used&=~(size_t)1;
		--this->ref_count;
		offset=(size_t)((char*)target_meta-arn_data(target_part));
 
		if(target_prev&&!(target_prev->size_and_used&1)){
			target_prev->size_and_used+=(target_meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
			target_meta=target_prev;
			offset=(size_t)((char*)target_meta-arn_data(target_part));
		}
		register size_t m_size=target_meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
		register size_t next_off=offset+m_size;
		if(next_off<target_part->cap){
			register shinsei_arena_meta_t* next=(shinsei_arena_meta_t*)(arn_data(target_part)+next_off);
			if(!(next->size_and_used&1)) target_meta->size_and_used+=(next->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
		}
 
		if(this->ref_count&&target_part==this->last_part&&target_prev){
			this->tail=(size_t)((char*)target_prev-arn_data(target_part));
		}
 
		m_size=target_meta->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1);
		if(m_size==target_part->cap){
			if(target_part==this&&this->next!=nullptr&&!arn_inlined(this)){
				shinsei_arena_t* next_part=this->next;
				__builtin_free(this->data);
				this->cap=next_part->cap;
				this->data=next_part->data;
				this->next=next_part->next;
				if(this->last_part==next_part) this->last_part=this;
				__builtin_free(next_part);
				this->head=0;
			}
			else if(target_part!=this){
				shinsei_arena_t* p=this;
				while(p->next!=target_part&&p->next!=nullptr) p=p->next;
				if(p->next==target_part){
					p->next=target_part->next;
					if(this->last_part==target_part){
						this->last_part=p;
						if(this->ref_count>0){
							size_t scan_off=0,new_tail=0;
							char* buf=arn_data(p);
							while(scan_off<p->cap){
								shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buf+scan_off);
								if(m->size_and_used&1) new_tail=scan_off;
								scan_off+=(m->size_and_used&~(size_t)(shinsei_arena_t_BYTE_ALIGNMENT-1));
							}
							this->tail=new_tail;
						}else{
							this->tail=0;
							this->head=0;
						}
					}
					__builtin_free(target_part->data);
					__builtin_free(target_part);
				}
			}
		}
	}
}

// Reference Count
size_t shinsei_arena_t_refCount(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ref_count;
}

// Check Empty
bool shinsei_arena_t_empty(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return !this->ref_count;
}

// Min Space
size_t shinsei_arena_t_minSpaceCapacity(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->min_space_cap;
}

// Max Space
size_t shinsei_arena_t_maxSpaceCapacity(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->max_space_cap;
}

// Clear all elements
void shinsei_arena_t_clear(shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ref_count=0;
	arn_initBlock(this,this->cap);
	return;
}

// Inlined check
bool shinsei_arena_t_inlined(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return arn_inlined(this);
}

// Get Ctrl
int_fast32_t shinsei_arena_t_getCtrl(const shinsei_arena_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

// Set Ctrl
void shinsei_arena_t_setCtrl(shinsei_arena_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// arena_custom_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool arn_custom_inlined(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal, const] Get the element data
_SHINSEI_OS_INLINE static char* arn_custom_data(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return (char*)((uintptr_t)&this->data*arn_custom_inlined(this)+!arn_custom_inlined(this)*(uintptr_t)this->data);
}

// [Internal] Free all chained elements
_SHINSEI_OS_INLINE static void arn_custom_freeData(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_custom_t* cur=this->next;
	while(cur!=nullptr){
		register shinsei_arena_custom_t* nxt=cur->next;
		if(!arn_custom_inlined(cur)){
			this->free_callback(cur->data);
			__builtin_free(cur);
		}
		cur=nxt;
	}
	if(!arn_custom_inlined(this)) this->free_callback(this->data);
	return;
}

// [Internal] Init arena structure
_SHINSEI_OS_INLINE static void arn_custom_initBlock(shinsei_arena_custom_t*const restrict this,const size_t cap)_SHINSEI_OS_NOEXCEPT{
	this->ref_count=0;
	this->head=0;
	this->tail=0;
	this->min_space_cap=cap;
	this->max_space_cap=cap;
	this->next=nullptr;
	this->last_part=this;
	
	register shinsei_arena_meta_t* meta=(shinsei_arena_meta_t*)arn_custom_data(this);
	meta->ctrl=0;
	meta->size_and_used=cap;
	return;
}

// [Internal] Allocate next part safely
_SHINSEI_OS_INLINE static shinsei_arena_custom_t* arn_custom_expandPart(shinsei_arena_custom_t*const restrict this,const size_t target_sz)_SHINSEI_OS_NOEXCEPT{
	register size_t next_cap=this->last_part->cap;
	while(next_cap<target_sz){
		register size_t proposed=next_cap<<1;
		if(__builtin_expect(proposed<next_cap,0)) proposed=target_sz;
		next_cap=proposed;
	}
	register shinsei_arena_custom_t*const new_part=(shinsei_arena_custom_t*)__builtin_malloc(sizeof(shinsei_arena_custom_t));
	if(__builtin_expect(new_part==nullptr,0)) return nullptr;
	new_part->ctrl=0;
	new_part->cap=next_cap;
	new_part->allocate_callback=this->allocate_callback;
	new_part->free_callback=this->free_callback;
	new_part->data=(char*)this->allocate_callback(next_cap);
	if(__builtin_expect(new_part->data==nullptr,0)){
		__builtin_free(new_part);
		return nullptr;
	}
	arn_custom_initBlock(new_part,next_cap);
	this->last_part->next=new_part;
	this->last_part=new_part;
	return new_part;
}

// Default constructor
shinsei_arena_custom_t* shinsei_arena_custom_t_con(const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT{
	register shinsei_arena_custom_t*const this=(shinsei_arena_custom_t*const)__builtin_malloc(sizeof(shinsei_arena_custom_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	if(__builtin_expect(!shinsei_arena_custom_t_as(this,cap,allocate_callback,free_callback),0)){
		__builtin_free(this);
		return nullptr;
	}
	return this;
}

// Free all chained elements
void shinsei_arena_custom_t_freeData(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	arn_custom_freeData(this);
	return;
}

// Destructor
void shinsei_arena_custom_t_dec(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	arn_custom_freeData(this);
	__builtin_free(this);
	return;
}

// Static Constructor
bool shinsei_arena_custom_t_as(shinsei_arena_custom_t*const restrict this,const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=0;
	this->cap=cap;
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	this->data=(char*)this->allocate_callback(cap);
	if(__builtin_expect(this->data==nullptr,0)) return false;
	arn_custom_initBlock(this,cap);
	return true;
}

// Inline Constructor
void shinsei_arena_custom_t_inl(shinsei_arena_custom_t*const restrict this,const size_t cap,shinsei_allocate_callback_t allocate_callback,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=_SHINSEI_CTRL_INLINED;
	this->cap=cap;
	this->allocate_callback=allocate_callback;
	this->free_callback=free_callback;
	arn_custom_initBlock(this,cap);
	return;
}

// Allocate from First available spot
void* shinsei_arena_custom_t_allocFront(shinsei_arena_custom_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT{
	register const size_t real_cost=(sizeof(shinsei_arena_meta_t)+needed_cap+(shinsei_arena_custom_t_BYTE_ALIGNMENT-1))&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	register shinsei_arena_custom_t* part=this;
	register shinsei_arena_meta_t* meta=nullptr;
	register size_t offset=0;
	register size_t m_size=0;
	
	meta=(shinsei_arena_meta_t*)arn_custom_data(this);
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	if(!(meta->size_and_used&1)&&m_size>=real_cost){
		goto allocate_block;
	}

	while(part!=nullptr){
		offset=0;
		register char*const buffer=arn_custom_data(part);
		while(offset<part->cap){
			meta=(shinsei_arena_meta_t*)(buffer+offset);
			m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
			if(!(meta->size_and_used&1)&&m_size>=real_cost) goto allocate_block;
			offset+=m_size;
		}
		part=part->next;
	}
	
	if(arn_custom_inlined(this)) return nullptr;
	part=arn_custom_expandPart(this,real_cost);
	if(__builtin_expect(part==nullptr,0)) return nullptr;
	meta=(shinsei_arena_meta_t*)arn_custom_data(part);
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	offset=0;
	
allocate_block:
	if(m_size>=real_cost+sizeof(shinsei_arena_meta_t)+shinsei_arena_custom_t_BYTE_ALIGNMENT){
		register shinsei_arena_meta_t*const next_meta=(shinsei_arena_meta_t*)((char*)meta+real_cost);
		next_meta->ctrl=0;
		next_meta->size_and_used=m_size-real_cost;
		meta->size_and_used=real_cost|1;
	} else {
		meta->size_and_used|=1;
	}
	
	++this->ref_count;
	if(this->ref_count==1){
		this->head=offset;
		this->tail=offset;
	}
	return (void*)((char*)meta+sizeof(shinsei_arena_meta_t));
}

// Allocate from Last available spot
void* shinsei_arena_custom_t_allocBack(shinsei_arena_custom_t*const restrict this,const size_t needed_cap)_SHINSEI_OS_NOEXCEPT{
	register const size_t real_cost=(sizeof(shinsei_arena_meta_t)+needed_cap+(shinsei_arena_custom_t_BYTE_ALIGNMENT-1))&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	register shinsei_arena_custom_t* part=this->last_part;
	register shinsei_arena_meta_t* meta=nullptr;
	register shinsei_arena_meta_t* last_valid=nullptr;
	register size_t offset=0,last_offset=0;
	register size_t m_size=0;
	
	if(this->ref_count){
		shinsei_arena_meta_t* last_used=(shinsei_arena_meta_t*)(arn_custom_data(part)+this->tail);
		size_t after_offset=this->tail+(last_used->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
		if(after_offset<part->cap){
			meta=(shinsei_arena_meta_t*)(arn_custom_data(part)+after_offset);
			m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
			if(!(meta->size_and_used&1)&&m_size>=real_cost){
				last_valid=meta;
				last_offset=after_offset;
			}
		}
	}
	else{
		meta=(shinsei_arena_meta_t*)arn_custom_data(part);
		m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
		if(!(meta->size_and_used&1)&&m_size>=real_cost){
			last_valid=meta;
			last_offset=0;
		}
	}
	
	if(!last_valid){
		part=this;
		register shinsei_arena_custom_t* found_part=nullptr;
		while(part!=nullptr){
			offset=0;
			register char*const buffer=arn_custom_data(part);
			while(offset<part->cap){
				meta=(shinsei_arena_meta_t*)(buffer+offset);
				m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
				if(!(meta->size_and_used&1)&&m_size>=real_cost){
					last_valid=meta;
					last_offset=offset;
					found_part=part;
				}
				offset+=m_size;
			}
			part=part->next;
		}
		if(last_valid) part=found_part;
	}
	
	if(last_valid) meta=last_valid;
	else{
		if(arn_custom_inlined(this)) return nullptr;
		part=arn_custom_expandPart(this,real_cost);
		if(__builtin_expect(part==nullptr,0)) return nullptr;
		meta=(shinsei_arena_meta_t*)arn_custom_data(part);
		last_offset=0;
	}
	
	m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	if(m_size>=real_cost+sizeof(shinsei_arena_meta_t)+shinsei_arena_custom_t_BYTE_ALIGNMENT){
		register shinsei_arena_meta_t*const next_meta=(shinsei_arena_meta_t*)((char*)meta+m_size-real_cost);
		next_meta->ctrl=0;
		next_meta->size_and_used=real_cost|1; 
		meta->size_and_used=m_size-real_cost;
		meta=next_meta;
		last_offset+=m_size-real_cost;
	}
	else{
		meta->size_and_used|=1;
	}
	
	++this->ref_count;
	if(this->ref_count==1) this->head=last_offset;
	if(part==this->last_part) this->tail=last_offset;
	
	return (void*)((char*)meta+sizeof(shinsei_arena_meta_t));
}

// Free Front
void shinsei_arena_custom_t_freeFront(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!this->ref_count,0)) return;
	
	register shinsei_arena_custom_t* part=this;
	register char* buffer;
	register shinsei_arena_meta_t* prev=nullptr;
	register shinsei_arena_meta_t* meta=nullptr;
	register size_t offset=0;

	buffer=arn_custom_data(part);
	meta=(shinsei_arena_meta_t*)(buffer+this->head);
	if(meta->size_and_used & 1){
		offset=this->head;
		if(this->head>0){
			shinsei_arena_meta_t*const first=(shinsei_arena_meta_t*)buffer;
			if (!(first->size_and_used&1)&&(first->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1))==this->head) prev=first;
		}
		goto do_free;
	}
	
	while(part!=nullptr){
		offset=0;
		buffer=arn_custom_data(part);
		prev=nullptr;
		while(offset<part->cap){
			meta=(shinsei_arena_meta_t*)(buffer+offset);
			if(meta->size_and_used&1) goto do_free;
			prev=meta;
			offset+=(meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
		}
		part=part->next;
	}
	return;

do_free:
	meta->size_and_used&=~(size_t)1;
	--this->ref_count;
	
	if(prev&&!(prev->size_and_used&1)){
		prev->size_and_used+=(meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
		meta=prev;
		offset=(size_t)((char*)meta-buffer);
	}
	register size_t m_size=meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
	register size_t next_off=offset+m_size;
	if(next_off<part->cap){
		register shinsei_arena_meta_t* next=(shinsei_arena_meta_t*)(buffer+next_off);
		if(!(next->size_and_used&1)) meta->size_and_used+=(next->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
	}
	
	if(m_size==part->cap){
		if(part==this&&this->next!=nullptr&&!arn_custom_inlined(this)){
			shinsei_arena_custom_t* next_part=this->next;
			this->free_callback(this->data);
			this->cap=next_part->cap;
			this->data=next_part->data;
			this->next=next_part->next;
			if(this->last_part==next_part) this->last_part=this;
			__builtin_free(next_part);
			this->head=0;
		}
		else if(part!=this){
			shinsei_arena_custom_t* p=this;
			while(p->next!=part&&p->next!=nullptr) p=p->next;
			if(p->next==part){
				p->next=part->next;
				if(this->last_part==part){
					this->last_part=p;
					if(this->ref_count>0){
						size_t scan_off=0,new_tail=0;
						char* buf=arn_custom_data(p);
						while(scan_off<p->cap){
							shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buf+scan_off);
							if(m->size_and_used&1) new_tail=scan_off;
							scan_off+=(m->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
						}
						this->tail=new_tail;
					}else{
						this->tail=0;
						this->head=0;
					}
				}
				this->free_callback(part->data);
				__builtin_free(part);
			}
		}
	}
	else if(part==this&&this->ref_count&&next_off<part->cap){
		this->head=next_off;
	}
}

// Free Back
void shinsei_arena_custom_t_freeBack(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(__builtin_expect(!this->ref_count,0)) return;
	
	register shinsei_arena_custom_t* part=this->last_part;
	register shinsei_arena_custom_t* target_part=nullptr;
	register shinsei_arena_meta_t* target_meta=nullptr;
	register shinsei_arena_meta_t* target_prev=nullptr;
	register size_t offset=0;
	
	register char* buffer=arn_custom_data(part);
	register shinsei_arena_meta_t* prev=nullptr;
	while(offset<part->cap){
		register shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buffer+offset);
		if(offset==this->tail && (m->size_and_used & 1)){
			target_part=part;
			target_meta=m;
			target_prev=prev;
			break;
		}
		prev=m;
		offset+=(m->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
	}
	
	if(!target_meta){
		part=this;
		while(part!=nullptr){
			offset=0;
			buffer=arn_custom_data(part);
			prev=nullptr;
			while(offset<part->cap){
				register shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buffer+offset);
				if(m->size_and_used&1){
					target_part=part;
					target_meta=m;
					target_prev=prev;
				}
				prev=m;
				offset+=(m->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
			}
			part=part->next;
		}
	}
	
	if(target_meta){
		target_meta->size_and_used&=~(size_t)1;
		--this->ref_count;
		offset=(size_t)((char*)target_meta-arn_custom_data(target_part));
 
		if(target_prev&&!(target_prev->size_and_used&1)){
			target_prev->size_and_used+=(target_meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
			target_meta=target_prev;
			offset=(size_t)((char*)target_meta-arn_custom_data(target_part));
		}
		register size_t m_size=target_meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
		register size_t next_off=offset+m_size;
		if(next_off<target_part->cap){
			register shinsei_arena_meta_t* next=(shinsei_arena_meta_t*)(arn_custom_data(target_part)+next_off);
			if(!(next->size_and_used&1)) target_meta->size_and_used+=(next->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
		}
 
		if(this->ref_count&&target_part==this->last_part&&target_prev){
			this->tail=(size_t)((char*)target_prev-arn_custom_data(target_part));
		}
 
		m_size=target_meta->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1);
		if(m_size==target_part->cap){
			if(target_part==this&&this->next!=nullptr&&!arn_custom_inlined(this)){
				shinsei_arena_custom_t* next_part=this->next;
				this->free_callback(this->data);
				this->cap=next_part->cap;
				this->data=next_part->data;
				this->next=next_part->next;
				if(this->last_part==next_part) this->last_part=this;
				__builtin_free(next_part);
				this->head=0;
			}
			else if(target_part!=this){
				shinsei_arena_custom_t* p=this;
				while(p->next!=target_part&&p->next!=nullptr) p=p->next;
				if(p->next==target_part){
					p->next=target_part->next;
					if(this->last_part==target_part){
						this->last_part=p;
						if(this->ref_count>0){
							size_t scan_off=0,new_tail=0;
							char* buf=arn_custom_data(p);
							while(scan_off<p->cap){
								shinsei_arena_meta_t* m=(shinsei_arena_meta_t*)(buf+scan_off);
								if(m->size_and_used&1) new_tail=scan_off;
								scan_off+=(m->size_and_used&~(size_t)(shinsei_arena_custom_t_BYTE_ALIGNMENT-1));
							}
							this->tail=new_tail;
						}else{
							this->tail=0;
							this->head=0;
						}
					}
					this->free_callback(target_part->data);
					__builtin_free(target_part);
				}
			}
		}
	}
}

// Reference Count
size_t shinsei_arena_custom_t_refCount(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ref_count;
}

// Check Empty
bool shinsei_arena_custom_t_empty(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return !this->ref_count;
}

// Min Space
size_t shinsei_arena_custom_t_minSpaceCapacity(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->min_space_cap;
}

// Max Space
size_t shinsei_arena_custom_t_maxSpaceCapacity(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->max_space_cap;
}

// Clear all elements
void shinsei_arena_custom_t_clear(shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	this->ref_count=0;
	arn_custom_initBlock(this,this->cap);
	return;
}

// Inlined check
bool shinsei_arena_custom_t_inlined(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return arn_custom_inlined(this);
}

// Get Ctrl
int_fast32_t shinsei_arena_custom_t_getCtrl(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

// Set Ctrl
void shinsei_arena_custom_t_setCtrl(shinsei_arena_custom_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

// Callback getter / setters
shinsei_allocate_callback_t shinsei_arena_custom_t_getAllocateCallback(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->allocate_callback;
}
void shinsei_arena_custom_t_setAllocateCallback(shinsei_arena_custom_t*const restrict this,shinsei_allocate_callback_t allocate_callback)_SHINSEI_OS_NOEXCEPT{
	this->allocate_callback=allocate_callback;
	return;
}
shinsei_free_callback_t shinsei_arena_custom_t_getFreeCallback(const shinsei_arena_custom_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->free_callback;
}
void shinsei_arena_custom_t_setFreeCallback(shinsei_arena_custom_t*const restrict this,shinsei_free_callback_t free_callback)_SHINSEI_OS_NOEXCEPT{
	this->free_callback=free_callback;
	return;
}

// spinlock_t

// [Internal, const] Check if elements are inlined
_SHINSEI_OS_INLINE static bool spin_inlined(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl&_SHINSEI_CTRL_INLINED;
}

// [Internal] Lock
_SHINSEI_OS_INLINE static void spin_lock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	#if(defined(_SHINSEI_OS_GNUC_4_7)||defined(_SHINSEI_OS_CLANG))
		while(__atomic_exchange_n(&this->flag,1,__ATOMIC_ACQUIRE)){
			cPUPause();
		}
	#elif(defined(_SHINSEI_OS_MSVC))
		while(_InterlockedExchange((volatile long*)&this->flag,1)){
			cPUPause();
		}
	#else
		while(this->flag) cPUPause();
		this->flag=1;
	#endif
	return;
}

// [Internal] Unlock
_SHINSEI_OS_INLINE static void spin_unlock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	#if(defined(_SHINSEI_OS_GNUC_4_7)||defined(_SHINSEI_OS_CLANG))
		__atomic_store_n(&this->flag,0,__ATOMIC_RELEASE);
	#elif(defined(_SHINSEI_OS_MSVC))
		_InterlockedExchange((volatile long*)&this->flag,0);
	#else
		this->flag=0;
	#endif
	return;
}

// [Internal] Default constructor
_SHINSEI_OS_INLINE static void spin_as(shinsei_spinlock_t*const restrict this,const bool instant_lock,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	this->flag=0;
	if(instant_lock){
		this->lock_status=true;
		spin_lock(this);
	}
	else this->lock_status=false;
	return;
}

// Default constructor
shinsei_spinlock_t* shinsei_spinlock_t_con(const bool instant_lock)_SHINSEI_OS_NOEXCEPT{
	#if(!defined(_SHINSEI_OS_ATOMIC)&&!defined(_SHINSEI_WARN_DISABLE_THREAD_SAFETY))
		#warning "[shinsei] spinlock_t(): Unsupported platform. Can't guarantee thread safety!"
	#endif
	register shinsei_spinlock_t*const this=(shinsei_spinlock_t*const)__builtin_malloc(sizeof(shinsei_spinlock_t));
	if(__builtin_expect(this==nullptr,0)) return nullptr;
	spin_as(this,instant_lock,0);
	return this;
}

// Destructor
void shinsei_spinlock_t_dec(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	if(this->lock_status) spin_unlock(this);
	__builtin_free(this);
	return;
}

// [Const] Check if the lock is using
bool shinsei_spinlock_t_locked(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->lock_status;
}

// Lock
void shinsei_spinlock_t_lock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	#if(!defined(_SHINSEI_OS_ATOMIC)&&!defined(_SHINSEI_WARN_DISABLE_THREAD_SAFETY))
		#warning "[shinsei] spinlock_t.lock(): Unsupported platform. Can't guarantee thread safety!"
	#endif
	this->lock_status=true;
	spin_lock(this);
	return;
}

// Unlock
void shinsei_spinlock_t_unlock(shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	#if(!defined(_SHINSEI_OS_ATOMIC)&&!defined(_SHINSEI_WARN_DISABLE_THREAD_SAFETY))
		#warning "[shinsei] spinlock_t.unlock(): Unsupported platform. Can't guarantee thread safety!"
	#endif
	this->lock_status=false;
	spin_unlock(this);
	return;
}

// Static default constructor
void shinsei_spinlock_t_as(shinsei_spinlock_t*const restrict this,const bool instant_lock)_SHINSEI_OS_NOEXCEPT{
	#if(!defined(_SHINSEI_OS_ATOMIC)&&!defined(_SHINSEI_WARN_DISABLE_THREAD_SAFETY))
		#warning "[shinsei] spinlock_t.as(): Unsupported platform. Can't guarantee thread safety!"
	#endif
	spin_as(this,instant_lock,0);
	return;
}

// Inline default constructor
void shinsei_spinlock_t_inl(shinsei_spinlock_t*const restrict this,const bool instant_lock)_SHINSEI_OS_NOEXCEPT{
	#if(!defined(_SHINSEI_OS_ATOMIC)&&!defined(_SHINSEI_WARN_DISABLE_THREAD_SAFETY))
		#warning "[shinsei] spinlock_t.inl(): Unsupported platform. Can't guarantee thread safety!"
	#endif
	spin_as(this,instant_lock,_SHINSEI_CTRL_INLINED);
	return;
}

// [const] Check if elements are inlined
bool shinsei_spinlock_t_inlined(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return spin_inlined(this);
}

// [Const] Get the ctrl code
int_fast32_t shinsei_spinlock_t_getCtrl(const shinsei_spinlock_t*const restrict this)_SHINSEI_OS_NOEXCEPT{
	return this->ctrl;
}

// Set the ctrl code
void shinsei_spinlock_t_setCtrl(shinsei_spinlock_t*const restrict this,const int_fast32_t ctrl)_SHINSEI_OS_NOEXCEPT{
	this->ctrl=ctrl;
	return;
}

#ifdef _SHINSEI_OS_CPP
}
#undef this
#endif