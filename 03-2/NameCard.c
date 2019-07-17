#include "NameCard.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NameCard * MakeNameCard(char * name, char * phone)
{
  NameCard * ptr = (NameCard *)malloc(sizeof(NameCard));

  strncpy(ptr->name, name, NAME_LEN-1);
  ptr->name[NAME_LEN-1] = 0;
  strncpy(ptr->phone, phone, PHONE_LEN-1);
  ptr->phone[PHONE_LEN-1] = 0;
  return ptr;
}

void ShowNameCardInfo(NameCard * pcard)
{
  printf("name: %s phone: %s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
  if(!strcmp(pcard->name, name))
      return 0;
  else
    return -1;
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
  strncpy(pcard->phone, phone, PHONE_LEN-1);
  pcard->phone[PHONE_LEN-1] = 0;
}
