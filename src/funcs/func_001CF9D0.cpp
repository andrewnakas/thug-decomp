struct ObjComponent {
    int m_data[6];
    virtual void V0();
    virtual void V1();
    virtual void V2(int arg);
    void CallV2_001CF9D0(int arg);
};

void ObjComponent::CallV2_001CF9D0(int arg)
{
    V2(arg);
}
