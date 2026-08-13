class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        MAX_INT = 2147483647
        MIN_INT = -2147483648
        
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
        if dividend == MIN_INT and divisor == 1:
            return MIN_INT
            
        is_negative = (dividend < 0) ^ (divisor < 0)
        
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        quotient = 0
        
        while dividend >= divisor:
            temp_divisor = divisor
            multiple = 1
            
            while dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
                
            dividend -= temp_divisor
            quotient += multiple
            
        if is_negative:
            quotient = -quotient
            
        return max(MIN_INT, min(MAX_INT, quotient))
