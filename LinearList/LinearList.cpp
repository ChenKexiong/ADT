#include <iostream>

using namespace std;

class List {
    InitList( &L );
    DestroyList( &L );
    ClearList( &L );
    ListEmpty( L );
    ListLength( L );
    GetElem( L, i, &e);
    LocateElem( L, e, compare());
    PriorElem( L, cur_e, &pre_e);
    NextElem( L, cur_e, &next_e);
    ListInsert( &L, i, e );
    ListDelete( &L, i, &e );
    ListTraverse( L, visit() );
}; // List

void union(List &La, List Lb) {
    La_len = ListLength(La), Lb_len = ListLength(Lb);
    for(i=1; i<=Lb_len; ++i) {
        GetElem(Lb, i, e);
        if(!LocateElem(La, e, equal)) ListInsert(La, ++La.len, e);
    }
} // union

void MergeList(List La, List Lb, List &Lc) {
    InitList(Lc);
    i = j = 1; k = 0;
    La_len = ListLength(La); Lb_len = ListLength(Lb);
    while((i <= La_len) && (j <= Lb_len)) {
        GetElem(La, i, ai); GetElem(Lb, j, bj);
        if(ai <= bj) { ListInsert(Lc, ++k, ai); ++i; }
        else { ListInsert(Lc, ++k, bj); ++j; }
    }
    while(i <= La_len) {
        GetElem(La, i++, ai); ListInsert(Lc, ++k, ai);
    }
    while(j <= Lb_len) {
        GetElem(Lb, j++, bj); ListInsert(Lc, ++k, bj);
    }
} // MergeList

#define LIST_INIT_SIZE      100
#define LISTINCREMENT      100
typedef struct {
    ElemType    *elem;
    int         length;
    int         listSize;
} SqList;

Status InitList_Sq(SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
} // InitList_Sq

Status ListInsert(SqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length+1) return ERROR;
    if(L.length >= L.listSize) {
        newbase = (ElemType *)realloc(L.elem,
                                      (L.listSize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listSize += LISTINCREMENT;
    }
    q = & (L.elem[i-1]);
    for(p = &(L.elem[L.length-1]); p >= q; --p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
    if((i < 1) || (i > L.length)) return ERROR;
    p = & (L.elem[i-1]);
    e = *p;
    q = L.elem + L.length - 1;
    for(++p; p <= q; ++p)
        *(p-1) = *q;
    --L.length;
    return OK;
} // ListDelete_Sq

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
