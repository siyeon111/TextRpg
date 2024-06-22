#pragma once
#include "Obj.h"

class Item :
    public CObj
{
public:
    Item();
    Item(INFO& info);
    Item(Item* item);
    virtual ~Item();


public:
    // CObj을(를) 통해 상속됨
    void Initialize() override;
    void Render() override;
    void LvUp();
public: //set
    void BEquip();
    void Set_Type(ITEM type);
    void Set_Value(int atk, int hp);
    void Set_Lv(int lv);
    void Set_Eq(bool type)
    {
        bEquip = type;
    }

public://get
    bool GetEquip();
    ITEM GetType();


private:
    bool bEquip;
    ITEM eItemType;
};

