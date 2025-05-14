MOD = 10**9 + 7

class Solution:
    def matrix_multiplication(self, A, B):
        res = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for j in range(26):
                for k in range(26):
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD
        return res

    def matrix_exponentiation(self, mat, t):
        res = [[1 if i == j else 0 for j in range(26)] for i in range(26)]  # identity matrix
        while t > 0:
            if t & 1:
                res = self.matrix_multiplication(mat, res)
            mat = self.matrix_multiplication(mat, mat)
            t >>= 1
        return res

    def lengthAfterTransformations(self, s: str, t: int, nums: list[int]) -> int:
        initial_freq = [0] * 26
        for c in s:
            initial_freq[ord(c) - ord('a')] += 1

        transformation_matrix = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for j in range(i + 1, i + 1 + nums[i]):
                transformation_matrix[j % 26][i] += 1

        res = self.matrix_exponentiation(transformation_matrix, t)

        final_array = [0] * 26
        for i in range(26):
            for j in range(26):
                final_array[i] = (final_array[i] + res[i][j] * initial_freq[j]) % MOD

        return sum(final_array) % MOD
