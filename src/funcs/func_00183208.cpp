/* sym: _$_14Table_00183208 = 0x00104F70 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Table_00183208 {
public:
    char m[0x4C];
    ~Table_00183208();
};

class Slot_00183208 {
public:
    int m0;
    Table_00183208 m_table;
    char pad50[0x44];
};

class Task_00183208 {
public:
    char pad[0x18];
    virtual void V1();
    virtual void V2();
    virtual ~Task_00183208();
};

class Owner_00183208 {
public:
    int m0;
    Task_00183208* m_task;
    Slot_00183208 m_slots[2];
    ~Owner_00183208();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Owner_00183208::~Owner_00183208()
{
    delete m_task;
}
