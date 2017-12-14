#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INFINITY 65535  //定义正无穷
#define ERROR -1
typedef struct ENode *PtrToENode;//边节点
struct ENode {
	int V1, V2;
	int Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;//图结构
struct GNode {
	int Nv;
	int Ne;
	int G[MAX][MAX];
	int Data[MAX];
};
typedef PtrToGNode MGraph;

//创建图并初始化
MGraph CreateGraph(int VertexNum) {
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(GNode));
	int i, j;
	for (i = 0; i < VertexNum; i++) {
		for (j = 0; j < VertexNum; j++) {
			Graph->G[i][j] = INFINITY;
		}
	}
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	return Graph;
}

//插入边
void InsertEdge(MGraph Graph, Edge E) {
	Graph->G[E->V1][E->V2] = E->Weight;
	//Graph->G[E->V2][E->V1] = E->Weight;

}

//建立图，在创建的初始图的基础上插入边
MGraph BuildGraph() {
	MGraph Graph;
	Edge E;
	E = (Edge)malloc(sizeof(ENode));
	int VertexNum;
	int i, j;
	printf("Input the num of vertex:");
	scanf_s("%d", &(VertexNum));
	Graph = CreateGraph(VertexNum);
	printf("Input the num of edge:");
	scanf("%d", &(Graph->Ne));
	for (i = 0; i < Graph->Ne; i++) {
		printf("Input V1 V2 Weight:");
		scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
		InsertEdge(Graph, E);
	}
	return Graph;

}

//------------以下的函数为Dijkstra算法的组成函数----------------
int FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* 返回未被收录顶点中dist最小者 */
	int MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			/* 若V未被收录，且dist[V]更小 */
			MinDist = dist[V]; /* 更新最小距离 */
			MinV = V; /* 更新对应顶点 */
		}
	}
	if (MinDist < INFINITY) /* 若找到最小dist */
		return MinV; /* 返回对应的顶点下标 */
	else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], int S)
{
	int collected[MAX];
	int V, W;

	/* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V]<INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* 先将起点收入集合 */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = 未被收录顶点中dist最小者 */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* 若这样的V不存在 */
			break;      /* 算法结束 */
		collected[V] = true;  /* 收录V */
		for (W = 0; W<Graph->Nv; W++) /* 对图中的每个顶点W */
									  /* 若W是V的邻接点并且未被收录 */
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (Graph->G[V][W]<0) /* 若有负边 */
					return false; /* 不能正确解决，返回错误标记 */
								  /* 若收录V使得dist[W]变小 */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
					path[W] = V; /* 更新S到W的路径 */
				}
			}
	} /* while结束*/
	return true; /* 算法执行完毕，返回正确标记 */
}

int main() {
	MGraph Graph;
	int i, j;
	int dist[MAX];
	int path[MAX];
	Graph = BuildGraph();
	Dijkstra(Graph, dist, path, 0);
	for (i = 0; i < Graph->Nv; i++) {
		printf("%d  %3d %8d\n", i, dist[i], path[i]);
	}
	return 0;
}
