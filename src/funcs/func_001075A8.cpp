struct C_001075A8 {
    char pad[0xD0];
    int m_D0;
    int pad2[2];
    int m_DC;
    void Update();
};

extern "C" void func_00107638(C_001075A8*);
extern "C" void func_00107730(C_001075A8*);
extern "C" void func_00107690(C_001075A8*);

void C_001075A8::Update()
{
    switch (m_DC) {
    case 5:
        func_00107638(this);
        break;
    case 1:
        func_00107730(this);
        break;
    case 3:
        m_D0 = 1;
        m_DC = 2;
        break;
    case 4:
        m_D0 = 0;
        m_DC = 2;
        break;
    case 2:
        func_00107690(this);
        break;
    case 0:
        break;
    }
}
