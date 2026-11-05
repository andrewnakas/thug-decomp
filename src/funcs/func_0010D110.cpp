struct Buf_0010D110 {
    int m0;
    int m_pos;
    Buf_0010D110* Back(int n);
};

Buf_0010D110* Buf_0010D110::Back(int n)
{
    m_pos -= n;
    return this;
}
