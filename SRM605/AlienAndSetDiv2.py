class AlienAndSetDiv2:
    def getNumber(self, N, K):
        MOD = 1000000007
        memory = dict()
        def gao(n, Set):
            if (n, Set) not in memory:
                ret = 0
                if n == 0:
                    ret = 1 if (Set == ()) else 0
                elif Set == ():
                    ret = 2 * gao(n - 1, (n, ))
                else:
                    ret += gao(n - 1, Set[1:])
                    if Set[0] != n + K:
                        ret += gao(n - 1, Set + (n, ))
                memory[(n, Set)] = ret
            return memory[(n, Set)]
        return gao(2 * N, ()) % MOD


