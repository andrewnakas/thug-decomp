struct Obj10E4A0 {
    char pad[0x34];
    int m34;
    bool Positive() const;
};

bool Obj10E4A0::Positive() const
{
    return m34 > 0;
}
