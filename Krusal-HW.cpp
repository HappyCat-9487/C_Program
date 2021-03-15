#include<stdio.h>

#define VER_LEN (101)
#define EDGE_LEN (10001)

typedef struct {
    int u, v;
    int cost;
} edge;

edge Edge[EDGE_LEN];
int Parent[VER_LEN];
int Size[VER_LEN];
int Flag[VER_LEN];

// 排序，按照邊的權重，從小到大排序
void sort(int edge_num) {
    int i, j;
    int temp_u, temp_v, temp_cost;

    for(i = 1; i < edge_num; i++) {
        for(j = 1; j <= edge_num - i; j++) {
            if(Edge[j].cost > Edge[j+1].cost) {
                temp_u = Edge[j].u;
                temp_v = Edge[j].v;
                temp_cost = Edge[j].cost;
                Edge[j].u = Edge[j+1].u;
                Edge[j].v = Edge[j+1].v;
                Edge[j].cost = Edge[j+1].cost;
                Edge[j+1].u = temp_u;
                Edge[j+1].v = temp_v;
                Edge[j+1].cost = temp_cost;
            }
        }
    }
}

void init(int ver_num) {
    int i;

    for(i = 1; i <= ver_num; i++) {
         // 將parent初始化?自身
        Parent[i] = i;
         // 將size初始化?1，用於按秩壓縮（如果不需要進行按秩壓縮，不需要這個數組信息）
        Size[i] = 1;
    }
}

int find(int vertex) {
    if(vertex != Parent[vertex]) {
        Parent[vertex] = find(Parent[vertex]); // 路徑壓縮
    }

    return Parent[vertex];
}

int union_set(int i) {
    int parent_u = find(Edge[i].u);
    int parent_v = find(Edge[i].v);

    // 節點u和v已經在同一顆樹上了
    if(parent_u == parent_v) {
        return 0;
    }

    // 按秩壓縮，將秩小一些的樹加入到秩大一些的樹
    if(Size[parent_u] > Size[parent_v]) {
        Parent[parent_v] = parent_u;
        Size[parent_u] += Size[parent_v];
    } else {
        Parent[parent_u] = parent_v;
        Size[parent_v] += Size[parent_u];
    }
    return 1;
}

void Kruskal(int ver_num, int edge_num) {
    int i;
    int counter;

    // 排序，按照邊的權重，從小到大排序
    sort(edge_num);

    // 進行初始化
    init(ver_num);

    counter = 0;
    // 按照邊的權重，從小到大遍歷所有的邊
    // 直到編譯完所有邊，或者生成了最小生成樹?止
    for(i = 1; i <= edge_num && counter < ver_num-1; i++) {
        // 當新加入的邊會形成環時，需要捨棄
        if(union_set(i) == 0) {
            continue;
        }

        // 將新加入的邊的編號保存在Flag數組中，以便輸入
        counter++;
        Flag[counter] = i;
    }
}

int main() {
    int i=1, j, a, b, c, max=0;
	int ver_num, edge_num;
    // freopen("input.txt", "r", stdin);

    while(scanf("%d %d %d", &a, &b, &c) != EOF){
    	a=Edge[i].u;
		b=Edge[i].v;
		c=Edge[i].cost;
		i++;
		if(a>max)
			max=a;
		if(b>max)
			max=b;
	}
   	edge_num=i-1;
    ver_num=max+1;

    Kruskal(ver_num, edge_num);
    
    printf("Adjacency list:\n");
    for(j=0;j<ver_num;j++){
    	if(Edge[j+1].u || Edge[j+1])
	}
	
	
	printf("minimum spanning tree:\n");
    for(i = 1; i < ver_num; i++)
        printf("%d: <%d,%d>\n", i, Edge[Flag[i]].u, Edge[Flag[i]].v);

    
    printf("\n");
	printf("The cost of minimum spanning tree: %d",);
    return 0;
}

