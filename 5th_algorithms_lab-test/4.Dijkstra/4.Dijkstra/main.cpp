#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define INFINITY 65535  //����������
#define ERROR -1
typedef struct ENode *PtrToENode;//�߽ڵ�
struct ENode {
	int V1, V2;
	int Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;//ͼ�ṹ
struct GNode {
	int Nv;
	int Ne;
	int G[MAX][MAX];
	int Data[MAX];
};
typedef PtrToGNode MGraph;

//����ͼ����ʼ��
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

//�����
void InsertEdge(MGraph Graph, Edge E) {
	Graph->G[E->V1][E->V2] = E->Weight;
	//Graph->G[E->V2][E->V1] = E->Weight;

}

//����ͼ���ڴ����ĳ�ʼͼ�Ļ����ϲ����
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

//------------���µĺ���ΪDijkstra�㷨����ɺ���----------------
int FindMinDist(MGraph Graph, int dist[], int collected[])
{ /* ����δ����¼������dist��С�� */
	int MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}

bool Dijkstra(MGraph Graph, int dist[], int path[], int S)
{
	int collected[MAX];
	int V, W;

	/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V]<INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	/* �Ƚ�������뼯�� */
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		/* V = δ����¼������dist��С�� */
		V = FindMinDist(Graph, dist, collected);
		if (V == ERROR) /* ��������V������ */
			break;      /* �㷨���� */
		collected[V] = true;  /* ��¼V */
		for (W = 0; W<Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
									  /* ��W��V���ڽӵ㲢��δ����¼ */
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (Graph->G[V][W]<0) /* ���и��� */
					return false; /* ������ȷ��������ش����� */
								  /* ����¼Vʹ��dist[W]��С */
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; /* ����dist[W] */
					path[W] = V; /* ����S��W��·�� */
				}
			}
	} /* while����*/
	return true; /* �㷨ִ����ϣ�������ȷ��� */
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
