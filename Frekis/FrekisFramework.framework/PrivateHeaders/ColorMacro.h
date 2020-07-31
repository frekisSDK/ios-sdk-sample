//
//  ColorMacro.h
//  项目中有用到的颜色宏定义
//
//  Created by Andy on 16/6/12.
//  Copyright © 2016年 Andy. All rights reserved.
//

#ifndef ColorMacro_h
#define ColorMacro_h

#ifdef __OBJC__
#pragma mark - Import Framework
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


#define kRGBWhiteColor [UIColor getColor:@"DDE3E1" alpha:1]           // 主打颜色-浅白色
#define kRGBBlackColor [UIColor getColor:@"20232B" alpha:1]           // 主打颜色-深黑色
#define kRGBGreenColor [UIColor getColor:@"60CBAC" alpha:1]           // 主打颜色-绿色
#define kRGBRedColor [UIColor getColor:@"FF7272" alpha:1]           // 主打颜色-红色
#define kRGBBlueColor [UIColor getColor:@"1A3F90" alpha:1]           // 主打颜色-蓝色

#endif
#endif /* ColorMacro_h */
