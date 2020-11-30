#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int cnt, r, c;                //当前有cnt个0 矩阵为 r行c列
    unordered_map<int, int> hash; //键：已经翻过的位置编号  值：该位置的替换编号
                                  //每当某一个位置翻过了 就用当时的最后一个位置去替换
    Solution(int n_rows, int n_cols) : cnt(n_rows * n_cols), r(n_rows), c(n_cols) {}
    vector<int> flip()
    {
        int x = rand() % cnt; //在0 ~ cnt-1内随机选一个位置
        int res = x;          //先假设x位置可以用
        if (hash.count(x))
        {
            res = hash[x]; //若x被用过了 则用替换x的新编号
        }
        //用当前最后一个位置去替换x位置
        if (hash.count(cnt - 1))
        {                                                 //若当前的最后一个位置也被用过了
            hash[x] = hash[cnt - 1], hash.erase(cnt - 1); //则更新x为新的cnt-1的编号 并删除cnt-1位置
        }
        else
            hash[x] = cnt - 1; //若最后一个位置没被用过 则直接换到x位置
        cnt--;                 //替换完毕 总元素减1
        return {res / c, res % c};
    }

    void reset()
    {
        cnt = r * c;
        hash.clear(); //最开始所有编号都没被用过
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
