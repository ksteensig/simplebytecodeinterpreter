#include "type.hpp"

namespace dlvm {

using namespace dlvm;
using namespace std;
//using namespace std::literals;


ReferenceType ValueType::Box() {
    return ReferenceType{type, Value};
}

Result<ValueType> ReferenceType::Unbox() {
    switch (type) {
        case ARRAY:
        case STRING:
        case STRUCT:
            return ThrowError<ValueType>("", INVALID_ARGUMENT);
        default:
            return OkResult<ValueType>(
                ValueType{type, get<VType>(Value)}
            );
    }
}

template<typename Type>
Result<Type> OkResult(Type value) {
    return Result<Type> {
            value
        };
}

template<typename Type>
Result<Type> TypeError(Type value) {
    return Result<Type> {
        value, "Type mismatch", TYPE_ERROR
    };
}

template<typename Type>
Result<Type> ThrowError(Type value, string msg, ErrorCode error_code) {
    return Result<Type> {
        value, msg, error_code
    };
}

template<typename Type>
Result<Type> ThrowError(string msg, ErrorCode error_code) {
    return Result<Type> {
        Type{}, msg, error_code
    };
}

/*
Result operator+ (Result lhs, Result rhs) {
    if (lhs.ErrCode != OK || rhs.ErrCode != OK) {
        return ThrowError("Invalid value", INVALID_ARGUMENT);
    }

    if (lhs.Value.type == INTEGER && rhs.Value.type == INTEGER) {
        return OkResult(
                Type{INTEGER,
                    get<int64_t>(lhs.Value.Value) +
                    get<int64_t>(rhs.Value.Value)}
            );
    } else {
        return TypeError(Type{});
    }
}
*/
/*
Result<Type> operator- (Type lhs, Type rhs) {
    if (lhs.type == INTEGER && rhs.type == INTEGER) {
        return OkResult<Type>(
            INTEGER,
            get<int64_t>(lhs.Value) - get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) - get<double>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == INTEGER) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) - get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == INTEGER && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<int64_t>(lhs.Value) - get<double>(rhs.Value)
        );
    } else {
        return TypeError<Type>(INTEGER, (int64_t)0);
    }
}

Result<Type> operator* (Type lhs, Type rhs) {
    if (lhs.type == INTEGER && rhs.type == INTEGER) {
        return OkResult<Type>(
            INTEGER,
            get<int64_t>(lhs.Value) * get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) * get<double>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == INTEGER) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) * get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == INTEGER && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<int64_t>(lhs.Value) * get<double>(rhs.Value)
        );
    } else {
        return TypeError<Type>(INTEGER, (int64_t)0);
    }
}

Result<Type> operator/ (Type lhs, Type rhs) {
    if (lhs.type == INTEGER && rhs.type == INTEGER) {
        return OkResult<Type>(
            INTEGER,
            get<int64_t>(lhs.Value) / get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) / get<double>(rhs.Value)
        );
    } else if (lhs.type == FLOAT && rhs.type == INTEGER) {
        return OkResult<Type>(
            FLOAT,
            get<double>(lhs.Value) / get<int64_t>(rhs.Value)
        );
    } else if (lhs.type == INTEGER && rhs.type == FLOAT) {
        return OkResult<Type>(
            FLOAT,
            get<int64_t>(lhs.Value) / get<double>(rhs.Value)
        );
    } else {
        return TypeError<Type>(INTEGER, (int64_t)0);
    }
}

Result<Type> operator&& (Type lhs, Type rhs) {
    if (lhs.type == BOOL && rhs.type == BOOL) {
        return OkResult<Type>(
                BOOL,
                get<bool>(lhs.Value) && get<bool>(rhs.Value)
            );
    } else {
        return TypeError<Type>(BOOL, false);
    }
}

Result<Type> operator|| (Type lhs, Type rhs) {
    if (lhs.type == BOOL && rhs.type == BOOL) {
        return OkResult<Type>(
                BOOL,
                get<bool>(lhs.Value) || get<bool>(rhs.Value)
            );
    } else {
        return TypeError<Type>(BOOL, false);
    }
}

Result<Type> operator! (Type rhs) {
    if (rhs.type == BOOL) {
        return OkResult<Type>(
                BOOL,
                !get<bool>(rhs.Value)
            );
    } else {
        return TypeError<Type>(BOOL, false);
    }
}
*/
/*
ostream& operator<< (ostream &o, Type t) {
    switch (t.type) {
        case INTEGER:
            o << get<int64_t>(t.Value);
            break;
        default:
            break;
    }

    return o;
}
*/

}