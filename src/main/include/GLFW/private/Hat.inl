namespace glfw {
    inline Hat operator| (Hat lhs, Hat rhs) noexcept {
        return static_cast<Hat> (static_cast<unsigned char> (lhs) | static_cast<unsigned char> (rhs));
    }    

    inline Hat operator& (Hat lhs, Hat rhs) noexcept {
        return static_cast<Hat> (static_cast<unsigned char> (lhs) & static_cast<unsigned char> (rhs));
    }

    inline Hat& operator|= (Hat& lhs, Hat rhs) noexcept {
        lhs = lhs | rhs;
        return lhs;
    }

    inline Hat& operator&= (Hat& lhs, Hat rhs) noexcept {
        lhs = lhs & rhs;
        return lhs;
    }
}
