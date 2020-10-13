//
//  BLETools.h
//  JINXK
//
//  Created by Andy on 2016/11/1.
//  Copyright © 2016年 Andy. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface BLETools : NSObject
#pragma mark - 解密
/**
 解密
 
 @param data 需要解密的数据
 @return 返回解密后的结果
 */
+ (NSData *)decryptWithData:(NSData *)data;

#pragma mark - 最新协议指令

/**
 获取token并校验密码
 
 @param password 密码
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)getTokenAndCheckPasswordWithPassword:(NSString *)password;

/**
 检测电量

 @param token 令牌
 @return 返回需要发送给设备的DATA
 */

+ (NSData *)getPowerWithToken:(NSData *)token;

/**
 开锁
 
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)unlockWithToken:(NSData *)token;

/**
 上锁
 
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)lockWithToken:(NSData *)token;

/**
 修改APP与设备连接的密码，第一包

 @param passwordOld 旧密码
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)changePasswordWithPasswordOld:(NSString *)passwordOld token:(NSData *)token;

/**
 修改APP与设备连接的密码，第二包

 @param passwordNew 新密码
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)changePasswordWithPasswordNew:(NSString *)passwordNew token:(NSData *)token;

/**
 设置自动开锁，on=YES，表示开启自动开锁，on=NO，表示关闭自动开锁

 @param on YES OR NO
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)setAutoUnlockWithOn:(BOOL)on token:(NSData *)token;

/**
 设置震动检测，on=YES，表示开启震动检测，on=NO，表示关闭震动检测

 @param on YES OR NO
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)setVibrationAlertWithOn:(BOOL)on token:(NSData *)token;

/**
 修改设备的名字 第一包，注：16个字节分两次发送，不满16个字节用空格代替

 @param name1 新名字的前8个字节
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)changeBLENameWithName1:(NSString *)name1 token:(NSData *)token;

/**
 修改设备的名字 第二包，注：16个字节分两次发送，不满16个字节用空格代替

 @param name2 新名字的后8个字节
 @param token 令牌
 @return return 返回需要发送给设备的DATA
 */
+ (NSData *)changeBLENameWithName2:(NSString *)name2 token:(NSData *)token;

/**
 设置托运模式，on=YES，表示开启托运模式，on=NO，表示关闭托运模式
 
 @param on YES OR NO
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)setConsignModelWithOn:(BOOL)on token:(NSData *)token;

/**
 查询锁状态

 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)getLockStateWithToken:(NSData *)token;

/**
 电机复位
 
 @param token 令牌
 @return 返回需要发送给设备的DATA
 */
+ (NSData *)setMotorResetWithToken:(NSData *)token;


#pragma mark - 旧指令

/**
 每次连接成功时，必须先发这第一条指令。
 只有收到指令返回并校验成功后，才能算是连接成功。
 
 @return 返回加密过的需要发送到蓝牙的数据
 */
+ (NSData *)getToken;

/**
 获取电量
 
 @return 返回加密后的数据
 */
+ (NSData *)getBattery;


///**
// 获取锁的状态
//
// @return 返回加密后的数据
// */
//+ (NSData *)getLockState;


/**
 开锁
 
 @return 返回加密后的数据
 */
+ (NSData *)setUnlock;

+ (NSData *)resetMotor;

+ (NSData *)testData;

@end
