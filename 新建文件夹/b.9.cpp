#include<stdio.h>
#include<stdlib.h>
#define MaxVex 20

typedef int EdgeType;
typedef char VertexType;

// �߽��ṹ������
typedef struct EdgeNode
{
    int adjvex;         // �ñ��ڽӵĽ���±�
    EdgeType edgeData;  // �ñ߽������ݣ�Ȩֵ��
    struct EdgeNode *next;
}EdgeNode, *EdgeList;

// ������ṹ��˳���
typedef struct
{
    VertexType vextexData;  // ��������
    EdgeList edgeList;      // ����ı����� 
    int indegree;           // ��������
    EdgeType earliest;      // �ö��������緢��ʱ��
    EdgeType latest;        // �ö�������ٷ���ʱ��
}VertexNode, *VertexList;

// �ڽӱ�ṹ
typedef struct
{
    VertexList vertexList; // ����˳���
    int numVertexs, numEdges;     // ������
}ALGraph;

// ��ʼ���ڽӱ�
void InitALGraph(ALGraph *G)
{

    G->numVertexs = 0;
    G->numEdges = 0;
    G->vertexList = (VertexNode *)malloc(MaxVex * sizeof(VertexNode));
    
    // ��ʼ��������ͷ��㣬�Ͷ������
    int i;
    for (i = 0; i < MaxVex; i++)
    {
        G->vertexList[i].edgeList = (EdgeNode *)malloc(sizeof(EdgeNode));
        G->vertexList[i].edgeList->next = NULL;
        G->vertexList[i].indegree = 0;
        G->vertexList[i].earliest = 0;
        G->vertexList[i].latest = 0;
    }
    printf("�ѳ�ʼ���ڽӱ�\n\n");
}

// �����ڽӱ�
void CreateALGraph(ALGraph *G)
{
    printf("�����붥�����ͱ���:");
    scanf("%d %d", &G->numVertexs, &G->numEdges);
    
    int i, j, k;
    EdgeType w;
    // ���붥������
    for (i = 0; i < G->numVertexs; i++)
    {
        fflush(stdin);
        printf("�������%d����������:", i + 1);
        scanf("%c", &G->vertexList[i].vextexData);
    }
    // ����ߵ�Ȩֵ
    for (k = 0; k < G->numEdges; k++)
    {
        printf("�������(vi, vj)�ϵĶ�����ż�Ȩֵ:");
        scanf("%d %d %d", &i, &j, &w);

        EdgeNode *p1;
        p1 = (EdgeNode *)malloc(sizeof(EdgeNode));

        // ����ͷ�巨 ���� ���㣨vi -> vj���ı�
        p1->edgeData = w;
        p1->next = G->vertexList[i - 1].edgeList->next;
        G->vertexList[i - 1].edgeList->next = p1;
        p1->adjvex = j - 1;                 // �ñ��ڽ��Ŷ���j
        G->vertexList[j - 1].indegree++;    // �ڽӶ���j����ȼ�һ
    }
    printf("�Ѵ����ڽӱ�!\n\n");
}

// ��������
void KeyPath(ALGraph G)
{ 
    // ��һ������������һ��ջ�ṹ��top1Ϊջ��ָ��
    int top1 = 0, Stack[MaxVex];

    // ���ڴ洢�����������������ջ
    int top2 = 0, RStack[MaxVex];

    // ��ʼ��
    int i, indegree[MaxVex];
    for (i = 0; i < G.numVertexs; i++)
    {
        // ��ȡÿ����������
        indegree[i] = G.vertexList[i].indegree;
        // ��ʼ��ջ�������Ϊ0�Ķ�����ջ
        if (indegree[i] == 0)
        {
            Stack[top1++] = i;
        }
    }

    // ͨ������������㶥�������緢��ʱ��
    int v;
    EdgeNode *p;
    printf("��������:");
    while (top1 > 0)
    {
        // �����Ϊ0�Ķ����ջ
        i = Stack[--top1];
        // ��ջ������ջ��
        RStack[top2++] = i;
        printf("%c--->", G.vertexList[i].vextexData);
        // �����ö������еĺ�̶���
        for (p = G.vertexList[i].edgeList->next; p ; p = p->next)
        {
            v = p->adjvex;
            // ����̶������ȼ�һ
            indegree[v]--;
            // �����̶������Ϊ�㣬����ջ
            if (!indegree[v])
            {
                Stack[top1++] = v;
            }
            // �������к�̶��������緢��ʱ��
            if (G.vertexList[i].earliest + p->edgeData > G.vertexList[v].earliest)
            {
                G.vertexList[v].earliest = G.vertexList[i].earliest + p->edgeData;
            }
        }
    }   
    printf("\n");

    if (top2 < G.numVertexs)
    {
        printf("����ʧ��!���ڻ�·\n");
    }
    else
    {
        // ��ʼ����������ٷ���ʱ��
        v = RStack[--top2];
        for (i = 0; i < G.numVertexs; i++)
        {
            G.vertexList[i].latest = G.vertexList[v].earliest;
        }
        
        // ��������ջ���¶�������ٷ���ʱ��
        while (top2 > 0)
        {
            // �������λ�ȡ����
            i = RStack[--top2];
            for (p = G.vertexList[i].edgeList->next; p ; p = p->next)
            {
                // �ڽӵĺ�̶���
                v = p->adjvex;
                // ���¶�������ٷ���ʱ��
                if (G.vertexList[v].latest - p->edgeData < G.vertexList[i].latest)
                {
                    G.vertexList[i].latest = G.vertexList[v].latest - p->edgeData;
                }
            }
        }
    }    
}

void Display(ALGraph G)
{
    int i;
    printf("����\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%c\t", G.vertexList[i].vextexData);
    }
    printf("\n����\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%d\t", G.vertexList[i].earliest);
    }
    printf("\n���\t");
    for (i = 0; i < G.numVertexs; i++)
    {
        printf("%d\t", G.vertexList[i].latest);
    }
    printf("\n�ؼ�·��:");
    for (i = 0; i < G.numVertexs; i++)
    {
        if (G.vertexList[i].latest - G.vertexList[i].earliest == 0)
        {
            printf("%C--->", G.vertexList[i].vextexData);
        }
    }
    printf("\n");
}

int main()
{
    ALGraph G;
    InitALGraph(&G);
    CreateALGraph(&G);
    KeyPath(G);
    Display(G);
    system("pause");
    return 0;
}

