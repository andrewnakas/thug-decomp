struct Stream_001E3038;
extern "C" void func_001E2B10(Stream_001E3038* s);

struct Stream_001E3038 {
    int m0;
    int m_req;
    int m_state;
    int Update();
};

int Stream_001E3038::Update()
{
    switch (m_state) {
    case 1:
    case 4:
    case 5:
    case 6:
        return 0;
    case 0:
    case 2:
    case 3:
        switch (m_req) {
        case 0:
        case 2:
        case 3:
            m_state = 4;
            func_001E2B10(this);
            break;
        case 1:
            m_state = 3;
            break;
        }
        break;
    }
    return 1;
}
