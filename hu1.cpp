#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include "MahjongGB/MahjongGB.h" //include �㷬��
using namespace std;
bool toHu()
{
    vector<pair<string, pair<string, int> > > pack;//��ҵ����ƣ�ÿ���һ��stringΪ"PENG" "GANG" "CHI" ����֮һ���ڶ���- stringΪ�ƴ��루���Ʊ�ʾ�м��ƴ��룩��������int������ʱ��ʾ�ϼҡ��Լҡ��¼ҹ��ƣ���ʱ123��ʾ�ڼ������ϼҹ��ơ�
    vector<string> hand;//��ҵİ��ƣ�stringΪ�ƴ���
    string winTile;//�͵������ƴ���
    int flowerCount;//������
    bool isZIMO;//�Ƿ�Ϊ��������
    bool isJUEZHANG;//�Ƿ�Ϊ�;���
    bool isGANG;//���ڸܣ����ϵ��ʱΪǹ�ܺͣ�����������Ϊ���Ͽ���
    bool isLAST;//�Ƿ�Ϊ��ǽ���һ�ţ���������Ϊ���ֻش�������Ϊ��������
    int menFeng;//�ŷ磬0123��ʾ��������
    int quanFeng;//Ȧ�磬0123��ʾ��������);
    vector<pair<int, string>>Fan = MahjongFanCaculator(
        pack, hand, winTile, 0, isZIMO, isJUEZHANG, isGANG, isLAST, menFeng, quanFeng);//0���ﱾ���ǲ������������жϺ��Ʋ���Ҫ�жϲ���������ֵ:��������vector��ÿ��int��ʾ���������Ϊ�ܷ�����string��ÿ�����ε�����
    int sumFan = 0;
    for (int i = 0; i < Fan.size(); i++) {
        sumFan += Fan[i].first;
    }
    if (sumFan >= 8)return true;
    else return false;
}