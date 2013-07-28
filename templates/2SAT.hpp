/*
 * Package: StandardCodeLibrary.2SAT
 * Usage:
 * N:变量个数
 * */
#include <GraphTheory.StronglyConnectedComponents>

#define T(x) (x)
#define F(x) ((x)+N)
int N;
void build_2sat(int n)
{
	N=n;
	build_graph(N*2);
	/*
	A[x]				=add_edge(F(x),T(x));
	NOT A[x]			=add_edge(T(x),F(x));
	A[x] AND A[y]		=add_edge(F(x),T(x)),add_edge(F(y),T(y));
	A[x] AND NOT A[y]	=add_edge(F(x),T(x)),add_edge(T(y),F(y));
	A[x] OR A[y]		=add_edge(F(x),T(y)),add_edge(F(y),T(x));
	A[x] OR NOT A[y]	=add_edge(F(x),F(y)),add_edge(T(y),T(x));
	NOT (A[x] AND A[y])	=add_edge(T(x),F(y)),add_edge(T(y),F(x));
	NOT (A[x] OR A[y])	=add_edge(T(x),F(x)),add_edge(T(y),F(y));
	A[x] XOR A[y]		=add_edge(F(x),T(y)),add_edge(F(y),T(x)),add_edge(T(x),F(y)),add_edge(T(y),F(x));
	NOT (A[x] XOR A[y])	=add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
	A[x] XOR NOT A[y]	=add_edge(F(x),F(y)),add_edge(F(y),F(x)),add_edge(T(x),T(y)),add_edge(T(y),T(x));
	u到v有边表示选u必选v
	*/
}
bool possible_2sat()
{
	tarjan();
	rep(i,N) if (bl[T(i)]==bl[F(i)]) rtn false;
	rtn true;
}
