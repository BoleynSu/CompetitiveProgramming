/*
 * Package: Miscellaneous.Poker
 * Usage:
 * decode将字符串形式的牌面解码成pii 这个要视具体问题而定
 * get计算牌面的大小
 * */
#include <Core>

namespace Miscellaneous
{
namespace Poker
{

//pii 用x表示编号2,3,4,5,6,7,8,9,T(10),J,Q,K,A依次为0,1,2,3,4,5,6,7,8,9,10,11,12 花色用y表示
pii decode(const char* s)
{
	pii x;
	if ('2'<=s[0]&&s[0]<='9') x.x=s[0]-'2';
	else if (s[0]=='T') x.x=8;
	else if (s[0]=='J') x.x=9;
	else if (s[0]=='Q') x.x=10;
	else if (s[0]=='K') x.x=11;
	else if (s[0]=='A') x.x=12;
	x.y=s[1];
	rtn x;
}
/*
 * pii 用x表示牌的种类 用y来判断同种牌的大小 (x,y)越大牌越好
 * x=9 straight flush - five cards of the same suit in sequence, such as 10,9,8,7,6 of clubs; ace can be counted both as the highest card or as the lowest card - A,2,3,4,5 of hearts is a straight flush. But 4,3,2,A,K of hearts is not a straight flush - it's just a flush.
 * x=8 four of a kind - four cards of the same rank, such as four kings.
 * x=7 full house - three cards of one rank plus two cards of another rank
 * x=6 flush - five cards of the same suit (but not a straight flush)
 * x=5 straight - five cards in order - just like the straight flush, but mixed suits
 * x=4 three of a kind - three cards of one rank and two other cards
 * x=3 two pairs - two cards of one rank, two cards of another rank, and one more card
 * x=2 pair - two cards of the same rank
 * x=1 high card - none of the above
 *
 */
pii get(vpii cards)
{
	srt(cards);
	int pairCnt=0;
	int tripleCnt=0;
	int quadCnt=0;
	int pairEncode=0,singleEncode=0;
	bool isFlush=sz(cards)==5;
	bool isStraight=sz(cards)==5;
	rep(i,sz(cards)-1) if (cards[i].x==cards[i+1].x) pairCnt++;
	rep(i,sz(cards)-2) if (cards[i].x==cards[i+2].x) tripleCnt++;
	rep(i,sz(cards)-3) if (cards[i].x==cards[i+3].x) quadCnt++;
	if (tripleCnt) pairCnt-=tripleCnt+1;
	if (quadCnt) tripleCnt-=quadCnt+1;
	fdt(i,sz(cards)-1,0)
		if (i&&cards[i-1].x==cards[i].x) pairEncode=pairEncode*13+cards[i].x,i--;
		else singleEncode=singleEncode*13+cards[i].x;
	rep(i,sz(cards)-1) if (cards[i].y!=cards[i+1].y) isFlush=false;
	rep(i,sz(cards)-1) if (cards[i].x+1!=cards[i+1].x) isStraight=false;
	if (!isStraight)
	{
		isStraight=true;
		rep(i,sz(cards)-1) if (cards[i].x!=i) isStraight=false;
		if (cards.back().x!=12) isStraight=false;
	}
	if (isFlush&&isStraight) rtn pii(9,cards[4].x*13+cards[3].x);
	else if (quadCnt) rtn pii(8,cards[2].x);
	else if (tripleCnt&&pairCnt) rtn pii(7,cards[2].x);
	else if (isFlush) rtn pii(6,singleEncode);
	else if (isStraight) rtn pii(5,cards[4].x*13+cards[3].x);
	else if (tripleCnt) rtn pii(4,cards[2].x);
	else if (pairCnt==2) rtn pii(3,pairEncode*13+singleEncode);
	else if (pairCnt)
	{
		if (sz(cards)==5) rtn pii(2,pairEncode*13*13*13+singleEncode);
		else rtn pii(2,pairEncode*13*13*13+singleEncode*13*13-1);
	}
	else
	{
		if (sz(cards)==5) rtn pii(1,singleEncode);
		else rtn pii(1,singleEncode*13*13-1);
	}
}

}
}
