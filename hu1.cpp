#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include "MahjongGB/MahjongGB.h" //include 算番器
using namespace std;
bool toHu()
{
    vector<pair<string, pair<string, int> > > pack;//玩家的明牌，每组第一个string为"PENG" "GANG" "CHI" 三者之一，第二个- string为牌代码（吃牌表示中间牌代码），第三个int碰、杠时表示上家、对家、下家供牌，吃时123表示第几张是上家供牌。
    vector<string> hand;//玩家的暗牌，string为牌代码
    string winTile;//和的那张牌代码
    int flowerCount;//补花数
    bool isZIMO;//是否为自摸和牌
    bool isJUEZHANG;//是否为和绝张
    bool isGANG;//关于杠，复合点和时为枪杠和，复合自摸则为杠上开花
    bool isLAST;//是否为牌墙最后一张，复合自摸为妙手回春，否则为海底捞月
    int menFeng;//门风，0123表示东南西北
    int quanFeng;//圈风，0123表示东南西北);
    vector<pair<int, string>>Fan = MahjongFanCaculator(
        pack, hand, winTile, 0, isZIMO, isJUEZHANG, isGANG, isLAST, menFeng, quanFeng);//0那里本来是补花数，但是判断胡牌不需要判断补花，返回值:函数返回vector，每组int表示番数，求和为总番数，string是每个番形的描述
    int sumFan = 0;
    for (int i = 0; i < Fan.size(); i++) {
        sumFan += Fan[i].first;
    }
    if (sumFan >= 8)return true;
    else return false;
}