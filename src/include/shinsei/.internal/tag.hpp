#pragma once

namespace shinsei{
	// Static construction
	struct in_place_t{
		explicit in_place_t()=default;
	};
	_SHINSEI_OS_INLINE_VAR _SHINSEI_OS_CONSTEXPR in_place_t in_place{};
	
	// Inline construction
	struct inlined_t{
		explicit inlined_t()=default;
	};
	_SHINSEI_OS_INLINE_VAR _SHINSEI_OS_CONSTEXPR inlined_t inlined{};
	
	// Unsafe construction
	struct unsafe_t{
		explicit unsafe_t()=default;
	};
	_SHINSEI_OS_INLINE_VAR _SHINSEI_OS_CONSTEXPR unsafe_t unsafe{};
	// Code page construction
	struct code_page_t{
		explicit code_page_t()=default;
	};
	_SHINSEI_OS_INLINE_VAR _SHINSEI_OS_CONSTEXPR code_page_t code_page{};
}