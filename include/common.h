#ifndef __COMMON_H
#define __COMMON_H



#define CLASS_NAME_TO_ID(NAME)      NAME##_CLASS_ID
#define CLASS_NAME_TO_STR(NAME)     #NAME
#define CLASS_ID_TO_NAME(ID)        CLASS_##ID##_NAME

#define DECLARE_CLASS(NAME, ID) \
                    extern const char CLASS_##ID##_NAME[]; \
                    extern const int NAME##_CLASS_ID;

#define DEFINE_CLASS(NAME, ID) \
                    const char CLASS_##ID##_NAME[] = #NAME; \
                    const int NAME##_CLASS_ID = ID;



#endif /* __COMMON_H */
