def convert(s: str, numRows: int) -> str:
    i = 0
    j = 0
    m = 1
    n = 0
    coeffs = []
    for c in s:
        coeffs.append((i,j))
        if i == numRows - 1:
            m = -1
            n = 1
        if i == 0:
            m = 1
            n = 0
        i += m
        j += n
        
    return ''

s = 'PAYPALISHIRING'
convert(s, 5)
                