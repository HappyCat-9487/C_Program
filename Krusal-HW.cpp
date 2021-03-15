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

// �ƧǡA�����䪺�v���A�q�p��j�Ƨ�
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
         // �Nparent��l��?�ۨ�
        Parent[i] = i;
         // �Nsize��l��?1�A�Ω�������Y�]�p�G���ݭn�i��������Y�A���ݭn�o�ӼƲիH���^
        Size[i] = 1;
    }
}

int find(int vertex) {
    if(vertex != Parent[vertex]) {
        Parent[vertex] = find(Parent[vertex]); // ���|���Y
    }

    return Parent[vertex];
}

int union_set(int i) {
    int parent_u = find(Edge[i].u);
    int parent_v = find(Edge[i].v);

    // �`�Iu�Mv�w�g�b�P�@����W�F
    if(parent_u == parent_v) {
        return 0;
    }

    // �������Y�A�N���p�@�Ǫ���[�J�쯴�j�@�Ǫ���
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

    // �ƧǡA�����䪺�v���A�q�p��j�Ƨ�
    sort(edge_num);

    // �i���l��
    init(ver_num);

    counter = 0;
    // �����䪺�v���A�q�p��j�M���Ҧ�����
    // ����sĶ���Ҧ���A�Ϊ̥ͦ��F�̤p�ͦ���?��
    for(i = 1; i <= edge_num && counter < ver_num-1; i++) {
        // ��s�[�J����|�Φ����ɡA�ݭn�˱�
        if(union_set(i) == 0) {
            continue;
        }

        // �N�s�[�J���䪺�s���O�s�bFlag�Ʋդ��A�H�K��J
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

