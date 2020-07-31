//
//  BaseModel.h
//  所有的数据模型都继承此类，这是一个基类。
//  解析json给数据模型赋值时可以直接调用 initWithDictionary: 方法
//
//  Created by femtoapp's macbook pro  on 15/10/17.
//  Copyright (c) 2015年 femto. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseStrongModel.h"

@interface BaseModel : NSObject     //模型基类，自带一个使用字典创建对象的方法
+(id)initWithDictionary:(NSDictionary *)dict;
-(NSDictionary *)dictionaryByModel;
-(void)addSubModelToArrayWithDictionary:(NSArray *)dataArray Model:(Class)class Key:(NSString *)key;//向模型中的数组属性赋值一个数组数据源的方法,必须保证key值名字的属性在模型中存在并且为数组
@end
