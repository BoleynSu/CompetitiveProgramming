#include <StandardCodeLibrary>

using namespace StandardCodeLibrary::GraphTheory::Dinic_sAlgorithm;

int main()
{
	build_graph();
	S=0,T=2;
	add_edge(S,1,2);
	add_edge(S,T,3);
	add_edge(1,T,1);
	prt(dinic());
}
