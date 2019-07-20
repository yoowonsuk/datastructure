#include "BinaryTree.h"
#include <stdlib.h>

BtreeNode * MakeBTreeNode(void)
{
  BTreeNode * newBT = (BTreeNode *)malloc(sizeof(BTreeNode));
  newBT->right = newBT->left = NULL;
  return newBT;
}

BTData GetData(BTreeNode * bt)
{
  return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
  bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
  return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
  return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
  main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
  main->right = sub;
}
