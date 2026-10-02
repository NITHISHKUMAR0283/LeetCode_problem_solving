class Solution(object):
    def minQueenMoves(self, source, target):
        """
        :type source: List[int]
        :type target: List[int]
        :rtype: int
        """
        [srow ,scol] = source
        [trow,tcol] = target
        if srow==trow and scol==tcol:
            return 0
        if srow==trow or scol==tcol :
            return 1
        if abs(trow-srow) == abs(scol-tcol):
            return 1
        return 2