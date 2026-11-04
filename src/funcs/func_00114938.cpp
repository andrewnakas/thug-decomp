struct Obj114938 {
    char pad[0x10];
    int m10;
    void Toggle();
};

void Obj114938::Toggle()
{
    m10 ^= 1;
}
