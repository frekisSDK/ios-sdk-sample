//
//  FontMacro.h
//  字体宏定义
//
//  Created by Andy on 16/6/12.
//  Copyright © 2016年 Andy. All rights reserved.
//

#ifndef USFontMacro_h
#define USFontMacro_h

#define kSYSFont(size) [UIFont systemFontOfSize:size]

#define kSYSFont10 kSYSFont(10)

#define kSYSFont12 kSYSFont(12)

#define kSYSFont13 kSYSFont(13)

#define kSYSFont14 kSYSFont(14)

#define kSYSFont15 kSYSFont(15)

#define kSYSFont16 kSYSFont(16)

#define kSYSFont18 kSYSFont(18)


#define kFont(s) [UIFont systemFontOfSize:s]

#define kFont18 kFont(18)

#define kFont15 kFont(15)

#define kFont14 kFont(14)

#define kFont13 kFont(13)

#define kFont12 kFont(12)

#define kFont11 kFont(11)

#define kFont20 kFont(20)

#define kFont26 kFont(26)

// 自定义的字体
#define kCustomFont(s) [UIFont fontWithName:@"DIN Alternate" size:s]
#define kCustomFont11 kCustomFont(11)
#define kCustomFont14 kCustomFont(14)
#define kCustomFont20 kCustomFont(20)
#define kCustomFont24 kCustomFont(24)
#define kCustomFont36 kCustomFont(36)
#define kCustomFont42 kCustomFont(42)
#define kCustomFont48 kCustomFont(48)


#endif /* USFontMacro_h */
