#include <iostream>

using namespace std;

class List {
    InitList( &L );
    DestroyList( &L );
    ClearList( &L );
    ListEmpty( L );
    ListLength( L );
    GetElem( L, i, &e );
    LocateElem( L, e, compare() );
    PriorElem( L, cur_e, &pre_e );
    NextElem( L, cur_e, &next_e );
    ListInsert( &L, i, e );
    ListDelete( &L, i, &e);
    ListTraverse( L, visit() );
};

void union(List &La, List Lb) {
    La_len = ListLength(La); Lb_len = ListLength(Lb);
    for(i=1; i<=Lb_len; ++i) {
        GetElem(Lb, i, e);
        if(!LocateElem(La, e, equal)) ListInsert(La, ++ La_len, e);
    }
} // union

void MergeList(List La, List Lb, List &Lc) {
    InitList(Lc);
    i = j = 1; k = 0;
    La_len = ListLength(La); Lb_len = ListLength(Lb);
    while((i <= La_len) && (j <= Lb_len)) {
        GetElem(La, i, ai); GetElem(Lb, j, bj);
        if(ai <= bj) { ListInsert(Lc, ++k, ai; ++i }
        else { ListInsert(Lc, ++k, bj); ++j; }
    }
    while(i <= La_len) {
        GetElem(La, i++, ai); ListInsert(Lc, ++k, ai);
    }
    while(j <= Lb_len) {
        GetElem(Lb, j++, bj); ListInsert(Lc, ++k, bj);
    }
} // MergeList

// ------------- 线性表的动态分配顺序存储结构 ----------------
#define LIST_INIT_SIZE      100
#define LISTINCREMENT       10
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
    if(i < 1 || i > L.length + 1) return ERROR;
    if(L.length >= L.listSize) {
        newBase = (ElemType *)realloc(L.elem,
                                      (L.listSize + LISTINCREMENT) * sizeof(ElemType));
        if(!newBase) exit(OVERFLOW);
        L.elem = newBase;
        L.listSize += LISTINCREMENT;
    }
    q = &(L.elem[i - 1]);
    for(p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
    if((i < 1) || (i > L.length)) return ERROR;
    p = &(L.elem[i-1]);
    e = *p;
    q = L.elem + L.length - 1;
    for(++p; p<=q; ++p)
        *(p-1) = *p;
    --L.length;
    return OK;
} // ListDelete_Sq

int LocateElem_Sq(SqList L, ElemType e, Status (* compare)(ElemType, ElemType)) {
    i = 1;
    p = L.elem;
    while(i <= L.length && !(*compare)(*p++, e))
        ++i;
    if(i <= L.length) return i;
    else return 0;
} // LocateElem_Sq

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
    pa = La.elem; pb = Lb.elem;
    Lc.listSize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listSize * sizeof(ElemType));
    if(!Lc.elem) exit(OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
} // MergeList_Sq







