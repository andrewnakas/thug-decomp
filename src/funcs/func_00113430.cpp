struct Date_00113430 {
    unsigned char m_resv;
    unsigned char m_sec;
    unsigned char m_min;
    unsigned char m_hour;
    unsigned char m_day;
    unsigned char m_month;
    unsigned short m_year;
};

struct Ent_00113430 {
    Date_00113430 m_create;
    Date_00113430 m_modify;
    unsigned int m_size;
    unsigned short m_attr;
    unsigned short m_resv1;
    unsigned int m_resv2;
    unsigned int m_apl;
    char m_name[32];
};

struct Clock_00113430 {
    unsigned char stat;
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char pad;
    unsigned char day;
    unsigned char month;
    unsigned char year;
};

struct Time_00113430 {
    unsigned char m_sec;
    unsigned char m_min;
    unsigned char m_hour;
    unsigned char m_day;
    unsigned char m_month;
    unsigned char m_pad;
    unsigned short m_year;
};

struct File_00113430 {
    char pad0[0xC];
    File_00113430* m_next;
    File_00113430* m_prev;
    char pad14[4];
    char m_name[0x20];
    Time_00113430 m_create;
    Time_00113430 m_modify;
    unsigned int m_size;
    unsigned short m_flags;
};

extern Ent_00113430 D_003BCF40[32];
extern "C" int func_00323F98(int port, int slot, const char* name, int mode, int max, Ent_00113430* table);
extern "C" void* func_001046B0(int size);
extern "C" void func_003461E8(Clock_00113430* c);
extern "C" char* func_00331A9C(char* d, const char* s);

struct Card_00113430;
extern "C" File_00113430* func_00113900(void* mem, int a, Card_00113430* card);

struct Card_00113430 {
    int m0;
    int m_port;
    int m_slot;
    int m_err;
    int GetDir(const char* name, File_00113430* list);
};

extern "C" int func_00113000(Card_00113430* s);

static inline unsigned int ToBcd_00113430(unsigned int v) { return (v / 10) * 16 + v % 10; }
static inline unsigned int ToBcdY_00113430(unsigned int v) { return v % 10 + (v / 10) * 16; }
static inline int FromBcdY_00113430(unsigned char v) { return (v & 0xF) + (v >> 4) * 10; }
static inline int FromBcd_00113430(unsigned char v) { return (v >> 4) * 10 + (v & 0xF); }

int Card_00113430::GetDir(const char* name, File_00113430* list)
{
    for (int mode = 0;; mode++) {
        if (func_00323F98(m_port, m_slot, name, mode, 32, D_003BCF40)) {
            m_err = 8;
            return 0;
        }
        int n = func_00113000(this);
        for (int i = 0; i < n; i++) {
            File_00113430* f = func_00113900(func_001046B0(0x58), 0, this);
            func_00331A9C(f->m_name, D_003BCF40[i].m_name);
            f->m_size = D_003BCF40[i].m_size;
            f->m_flags = 0;
            if (D_003BCF40[i].m_attr & 0x1) f->m_flags = 1;
            if (D_003BCF40[i].m_attr & 0x2) f->m_flags |= 0x2;
            if (D_003BCF40[i].m_attr & 0x4) f->m_flags |= 0x4;
            if (D_003BCF40[i].m_attr & 0x8) f->m_flags |= 0x8;
            if (D_003BCF40[i].m_attr & 0x20) f->m_flags |= 0x10;
            if (D_003BCF40[i].m_attr & 0x80) f->m_flags |= 0x20;
            if (D_003BCF40[i].m_attr & 0x800) f->m_flags |= 0x40;
            if (D_003BCF40[i].m_attr & 0x1000) f->m_flags |= 0x80;
            Clock_00113430 c;
            c.day = ToBcd_00113430(D_003BCF40[i].m_modify.m_day);
            c.hour = ToBcd_00113430(D_003BCF40[i].m_modify.m_hour);
            c.minute = ToBcd_00113430(D_003BCF40[i].m_modify.m_min);
            c.month = ToBcd_00113430(D_003BCF40[i].m_modify.m_month);
            c.second = ToBcd_00113430(D_003BCF40[i].m_modify.m_sec);
            c.year = ToBcdY_00113430(D_003BCF40[i].m_modify.m_year % 100);
            func_003461E8(&c);
            f->m_modify.m_sec = FromBcd_00113430(c.second);
            f->m_modify.m_min = FromBcd_00113430(c.minute);
            f->m_modify.m_hour = FromBcd_00113430(c.hour);
            f->m_modify.m_day = FromBcd_00113430(c.day);
            f->m_modify.m_month = FromBcd_00113430(c.month);
            f->m_modify.m_year = FromBcdY_00113430(c.year) + 2000;
            c.day = ToBcd_00113430(D_003BCF40[i].m_create.m_day);
            c.hour = ToBcd_00113430(D_003BCF40[i].m_create.m_hour);
            c.minute = ToBcd_00113430(D_003BCF40[i].m_create.m_min);
            c.month = ToBcd_00113430(D_003BCF40[i].m_create.m_month);
            c.second = ToBcd_00113430(D_003BCF40[i].m_create.m_sec);
            c.year = ToBcdY_00113430(D_003BCF40[i].m_create.m_year % 100);
            func_003461E8(&c);
            f->m_create.m_sec = FromBcd_00113430(c.second);
            f->m_create.m_min = FromBcd_00113430(c.minute);
            f->m_create.m_hour = FromBcd_00113430(c.hour);
            f->m_create.m_day = FromBcd_00113430(c.day);
            f->m_create.m_month = FromBcd_00113430(c.month);
            f->m_create.m_year = FromBcdY_00113430(c.year) + 2000;
            f->m_prev = list->m_prev;
            f->m_next = list;
            list->m_prev->m_next = f;
            list->m_prev = f;
        }
        if (n < 32) break;
    }
    return 1;
}
