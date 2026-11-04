struct Data_001EC2A0 {
    int m_name;
    int m_size;
    int m_packed;
    unsigned char m_data[1];
};

struct Entry_001EC2A0 {
    char m_0[2];
    unsigned char m_type;
    char m_3[0x8 - 3];
    int m_8;
    Data_001EC2A0* m_C;
};

extern void* D_0038E8A4;
extern "C" Entry_001EC2A0* func_001E5188(int name);
extern "C" void* func_0010BDE0(int size);
extern "C" int func_00105AF8(unsigned char* src, unsigned char* dst, int size, int a);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001F3180(void* mgr, int name);
extern "C" int func_00105520(char* s);

extern "C" Entry_001EC2A0* func_001EC2A0(int name, int id, unsigned char* src, int size, char* file)
{
    Entry_001EC2A0* e = func_001E5188(name);
    e->m_type = 7;
    unsigned char* buf = (unsigned char*)func_0010BDE0(20000);
    int len = func_00105AF8(src, buf, size, 0);
    if (len >= size) {
        unsigned char* s = src;
        unsigned char* d = buf;
        for (unsigned int i = 0; i < size; i++) {
            *d++ = *s++;
        }
        len = size;
    }
    Data_001EC2A0* data = (Data_001EC2A0*)func_0010BDE0(len + 0xC);
    data->m_name = id;
    data->m_size = size;
    data->m_packed = len;
    unsigned char* s = buf;
    unsigned char* d = data->m_data;
    for (int i = 0; i < len; i++) {
        *d++ = *s++;
    }
    e->m_C = data;
    func_0010BEB8(buf);
    if (D_0038E8A4) {
        func_001F3180(D_0038E8A4, name);
    }
    e->m_8 = func_00105520(file);
    return e;
}
