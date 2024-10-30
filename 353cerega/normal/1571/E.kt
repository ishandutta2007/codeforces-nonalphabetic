import java.util.*
import kotlin.math.max


/*fun cont(len: Int, cnt: Array<Int>): Long
{
    var L = len
    var ans: Long = 1
    cnt.sort()
    for (i in 0..8)
    {
        if (cnt[i]>60) return 2000000000
        for (j in 0..(cnt[i]-1))
        {
            ans *= L
            L--
            ans /= (j+1)
            if (ans>1000000000) return 1000000001
        }
    }
    return ans
}*/
var t = Array<Long>(1200000)
{
   0
}

fun upd(v: Int, tl: Int, tr: Int, p: Int, del: Long)
{
    t[v] += del
    if (tl==tr) return;
    var tm = (tl+tr)/2
    if (tm>=p) upd(v*2,tl,tm,p,del)
    else upd(v*2+1,tm+1,tr,p,del)
}

fun get(v: Int, tl: Int, tr: Int, l: Int, r: Int): Long
{
    if (tl==l && tr==r) return t[v]
    var tm = (tl+tr)/2
    if (tm>=r) return get(v*2,tl,tm,l,r)
    if (l>tm) return get(v*2+1,tm+1,tr,l,r)
    return get(v*2,tl,tm,l,tm)+get(v*2+1,tm+1,tr,tm+1,r)
}


fun main(args: Array<String>) = with(java.util.Scanner(System.`in`))
{
    //var n = nextInt()
    //var map: MutableMap<Int, Int>
    //var numbers: Array<Array<Int>> = Array(3, { Array(5, {0}) })
    //var numbers3: MutableSet<Int> = sortedSetOf(15, 16, 17)
    //var t = nextInt()
    //var n = nextInt()
    //var a = Array(n)
    //{
    //    100-it
    //}
    //var n = readLine()!!.toInt()
    //val spl = readLine()!!.split(' ').map(String::toInt)

    //var ord = Array(n)  { Pair(spl[it],it) }
    //ord.sortWith(compareBy({-it.first}, {it.second}))
    //for (i in 0..n-1)
    //{
    //     L[i+1] = max(b[i]-a[i],L[i])
    //}
    var t = readLine()!!.toInt()
    while (t>0)
    {
        t--
        var n = readLine()!!.toInt()
        var S = readLine()!!
        var A = readLine()!!
        var INF = 10000000
        var dp = Array(16)
        {
            INF
        }
        var dp2 = Array(16)
        {
            INF
        }
        dp[0] = 0
        for (i in 0..n-1)
        {
            for (j in 0..15)
            {
                dp2[j] = INF
            }
            for (j in 0..15)
            {
                var x = j/2
                if (S[i]=='(')
                {
                    if (dp2[x]>dp[j]) dp2[x] = dp[j]
                    if (dp2[x+8]>1+dp[j]) dp2[x+8] = dp[j]+1
                }
                else
                {
                    if (dp2[x+8]>dp[j]) dp2[x+8] = dp[j]
                    if (dp2[x]>1+dp[j]) dp2[x] = dp[j]+1
                }
            }
            if (i>=3 && A[i-3]=='1')
            {
                for (j in 0..15)
                {
                    if (j!=10 && j!=12) dp2[j] = INF
                }
            }
            for (j in 0..15) dp[j] = dp2[j]
        }
        var mn = INF
        for (j in 0..15)
        {
            if (mn>dp[j]) mn = dp[j]
        }
        if (mn==INF) println(-1)
        else println(mn)
    }
}