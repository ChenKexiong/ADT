// NLR
void PreOrder(BiTree T)
{
  if(T != NULL) {
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

// LNR
void InOrder(BiTree T)
{
  if(T != NULL) {
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

// LRN
void PostOrder(BiTree T)
{
  if(T != NULL) {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}

// Without Recursion
// LNR
void InOrder2(BiTree T)
{
  InitStack(S);
  BiTree p=T;
  while(p || !IsEmpty(S)) {
    if(p) {
      Push(S, p);
      p = p->lchild;
    }
    else {
      Pop(S, p); visit(p);
      p = p->rchild;
    }
  }
}

// Level Traversal
void LevelOrder(BiTree T)
{
  InitQueue(Q);
  BiTree p;
  EnQueue(Q, T);
  while(!IsEmpty(Q)) {
    DeQueue(Q, p);
    visit(p);
    if(p->lchild != NULL)
      EnQueue(Q, p->lchild);
    if(p->rchild != NULL)
      EnQueue(Q, p->rchild);
  }
}











