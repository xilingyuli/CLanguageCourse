#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 255
//MAX_LENָ����ÿ������haffman����ĳ���
#define MAX_LEN     100

struct tnode
{
    //���Ҷ��ӽڵ�
    struct tnode* left; /*used when in tree*/
    struct tnode*right; /*used when in tree*/
    //���׽ڵ㣬���ڴ�Ҷ�ӽڵ����������ڵ�
    struct tnode*parent; /*used when in tree*/
    struct tnode* next; /*used when in list*/
    //����Ƶ��
    float freq;
    //�ж��Ƿ�ΪҶ�ӽڵ�
    int isleaf;
    //��ĸ
    char symbol;
};


/*global variables*/
//�洢ÿ����ĸ�ı���
char code[MAX_SYMBOLS][MAX_LEN];
//���ĸ��ڵ�
struct tnode* root = NULL; /*tree of symbols*/
//����ͷ���
struct tnode* qhead = NULL; /*list of current symbols*/
struct tnode* chead = NULL; /*list of code*/

/*
    @function   talloc
    @desc       allocates new node
 */
//�½��Լ���ʼ���ڵ�

struct tnode* talloc(int symbol, float freq)
{
    struct tnode* p = (struct tnode*) malloc(sizeof (struct tnode));
    if (p != NULL)
    {
        p->left = p->right = p->parent = p->next = NULL;
        p->symbol = symbol;
        p->freq = freq;
        p->isleaf = 1;
    }
    return p;
}

/*
    @function display_tnode_list
    @desc     displays the list of tnodes during code construction
 */
//��ӡ��������

void pq_display(struct tnode* head)
{
    struct tnode* p = NULL;
    printf("list:");
    for (p = head; p != NULL; p = p->next)
    {
        printf("(%c,%f) ", p->symbol, p->freq);
    }
    printf("\n");
}

/*
    @function pq_insert
    @desc     inserts an element into the priority queue
    NOTE:     makes use of global variable qhead
 */
//�������

void pq_insert(struct tnode* p)
{
    struct tnode* curr = NULL;
    struct tnode* prev = NULL;
    printf("inserting:%c,%f\n", p->symbol, p->freq);
    if (qhead == NULL) /*qhead is null*/
    {
        /*TODO: write code to insert when queue is empty*/
        qhead = p;
    }
    /*TODO: write code to find correct position to insert*/
    else
    {
        for( curr = qhead;curr!=NULL && curr->freq < p->freq;curr = curr->next )
        {
            prev = curr;
        }
        if (curr == qhead)
        {
            /*TODO: write code to insert before the current start*/
            p->next = qhead;
            qhead = p;
        }
        else /*insert between prev and next*/
        {
            /*TODO: write code to insert in between*/
            p->next = curr;
            prev->next = p;
        }
    }
}

/*
    @function pq_pop
    @desc     removes the first element
    NOTE:     makes use of global variable qhead
 */
//���ض�����Ƶ����С�Ľڵ㣬��ɾ������

struct tnode* pq_pop()
{
    //��Ҫ����Ƶ����С�Ľڵ�
    struct tnode* p = NULL;
    /*TODO: write code to remove front of the queue*/
    if(qhead!=NULL)
    {
        p = qhead;
        printf("popped:%c,%f\n", p->symbol, p->freq);
        qhead = qhead->next;
        p->next = NULL;
    }
    return p;
}

/*
        @function build_code
        @desc     generates the string codes given the tree
        NOTE: makes use of the global variable root
 */
//ǰ��������������������ÿ��Ҷ�ӽڵ��0,1����

void generate_code(struct tnode* root, int depth)
{
    int symbol;
    int len; /*length of code*/
    if (root->isleaf)
    {
        //root��Ҷ�ӽڵ㣬len�����Ҷ�ӽڵ�0,1,����ĳ���symbolΪ�����ĸ
        symbol = root->symbol;
        len = depth;
        /*start backwards*/
        //�������ĸ�����0,1���е����һλ��ֵΪ'\0'
        code[symbol][len] = 0;
        //������Ҫ����д�������ĸ��0,1���С���������һֱ����Ҷ�Ӽ���root��
        //ͨ��fatherָ����������ĸ��ڵ㡣����������ж����Լ��������׽ڵ�
        //������ӻ����Ҷ��ӣ�������֪�������ĸ��0,1�����ˣ����浽code�м���
        /*
                TODO: follow parent pointer to the top
                to generate the code string
         */
         for(len--;len>0;len--)
         {
             if(root->parent->left==root)
             {
                 code[symbol][len] = '0';
             }
             else
             {
                 code[symbol][len] = '1';
             }
             root = root->parent;
         }
        if(root->parent->left==root)
        {
            code[symbol][len] = '0';
        }
        else
        {
            code[symbol][len] = '1';
        }
        printf("built code:%c,%s\n", symbol, code[symbol]);
    }
    else
    {
        generate_code(root->left, depth + 1);
        generate_code(root->right, depth + 1);
    }

}

/*
        @func	dump_code
        @desc	output code file
 */
//�����е�Ҷ�ӽڵ��0,1���뱣�浽code.txt�У������������
void dump_code(FILE* fp)
{
    int i = 0;
    for (i = 0; i < MAX_SYMBOLS; i++)
    {
        if (code[i][0]) /*non empty*/
            fprintf(fp, "%c %s\n", i, code[i]);
    }
}

/*
        @func	encode
        @desc	outputs compressed stream
 */
//ѹ���ļ���������ֱ�Ӱ�ÿ����ĸ���ĸ�0,1�ַ�����ʾ�ˣ�����ѹ����϶���󡣽���ʹ����ʵ��˵���еķ������ܴﵽ���������ϵ�ѹ����
void encode(char* str, FILE* fout)
{
    while (*str)
    {
        fprintf(fout, "%s", code[*str]);
        str++;
    }
}

void freetree(struct tnode* root)
{
    if (root == NULL)
        return;
    freetree(root->right);
    freetree(root->left);
    free(root);
}

/*
    @function main
 */
int main()
{
    /*test pq*/
    struct tnode* p = NULL;
    struct tnode* lc, *rc;
    //���������Լ������Ĵ�Ƶ���ݣ�ʵ����������Ҫ�Լ�͸���ļ���ͳ��һ��������ĸ���������ÿ����ĸ��Ƶ�ʡ��������Ϣֻ������ʹ��
    float freq[] = {0.01, 0.04, 0.05, 0.11, 0.19, 0.20, 0.4};
    int NCHAR = 7; /*number of characters*/
    int i = 0;
    const char *CODE_FILE = "code.txt";
    const char *OUT_FILE = "encoded.txt";
    FILE* fout = NULL;
    /*zero out code*/
    memset(code, 0, sizeof (code));
//���Զ��е���ȷ��
    /*testing queue*/
    pq_insert(talloc('a', 0.1));
    pq_insert(talloc('b', 0.2));
    pq_insert(talloc('c', 0.15));
    /*making sure it pops in the right order*/
    puts("making sure it pops in the right order");
    while ((p = pq_pop()))
    {
        free(p);
    }
//���Խ���
    qhead = NULL;
    /*initialize with freq*/
    //����
    for (i = 0; i < NCHAR; i++)
    {
        pq_insert(talloc('a' + i, freq[i]));
    }
    /*build tree*/
    for (i = 0; i < NCHAR - 1; i++)
    {
        lc = pq_pop();
        rc = pq_pop();
        /*create parent*/
        p = talloc(0, lc->freq + rc->freq);
        /*set parent link*/
        lc->parent = rc->parent = p;
        /*set child link*/
        p->right = rc;
        p->left = lc;
        /*make it non-leaf*/
        p->isleaf = 0;
        /*add the new node to the queue*/
        pq_insert(p);
    }
    /*get root*/
    root = pq_pop();
    /*build code*/
    generate_code(root, 0);
    /*output code*/
    puts("code:");
    fout = fopen(CODE_FILE, "w");
    dump_code(stdout);
    dump_code(fout);
    fclose(fout);
    //ѹ������
    /*encode a sample string*/
    puts("orginal:abba cafe bad");
    fout = fopen(OUT_FILE, "w");
    encode("abba cafe bad", stdout);
    encode("abba cafe bad", fout);
    fclose(fout);
    getchar();
    /*TODO: clear resources*/
    freetree(root);
    return 0;
}
