struct C_001F4FA8 {
    char m_pad[0xA94];
    int mA94;
    int mA98;
    void Count(unsigned int name);
};

void C_001F4FA8::Count(unsigned int name)
{
    switch (name) {
    case 0xBA15FC7F:
        mA94++;
        break;
    case 0xB9AE26D2:
        mA98++;
        break;
    }
}
