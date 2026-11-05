struct C_00252B60;
extern "C" unsigned int func_002521A0(C_00252B60* self);

struct C_00252B60 {
    char m_pad[0x434];
    unsigned int m434;
    void Next();
};

void C_00252B60::Next()
{
    m434++;
    if (m434 >= func_002521A0(this)) m434 = 0;
}
