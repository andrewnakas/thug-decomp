extern "C" void* memcpy(void*, const void*, unsigned int);

struct Str6_002521D0 {
    int a;
    short b;
};
extern Str6_002521D0 D_00390738[];

class Obj_002521D0 {
public:
    Obj_002521D0();
    char pad0[0x10];
    Str6_002521D0 m_name;
    char pad18[0x434 - 0x18];
    int m_434;
};

Obj_002521D0::Obj_002521D0()
{
    memcpy(&m_name, D_00390738, 6);
    m_434 = 0;
}
