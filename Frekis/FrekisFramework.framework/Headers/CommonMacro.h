//
//  CommonMacro.h
//  GoldenPhoenix
//
//  Created by Andy on 2017/11/7.
//  Copyright © 2017年 FL SMART. All rights reserved.
//

#ifndef CommonMacro_h
#define CommonMacro_h

#ifdef DEBUG
#define DEBUGLOG(xx, ...)  NSLog(@"############### BLE HELPER ############### %s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#elif RELEASE
#define DEBUGLOG(xx, ...)  ((void)0)
#else
#define DEBUGLOG(xx, ...)  ((void)0)
#endif

#define WS(weakSelf,self) __weak __typeof(self) weakSelf = self

#define kAppDelegate [Frekis shared]
#define kWLBLE [WLBLEManager shareInstance]
#define kWLBLEDataModel [WLBLEDataModel shareInstance]
#define kWLHttpRequest [WLHttpRequest shareWLHttpRequest]

#define kWLBLEM [WLBLEManagement shareInstance]


// 系统判定
#define SYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

// 多语言设置
#define AppLanguage @"appLanguage"

// 蓝牙的密码与ID
#define kBLE_PASSWORD_UserDefaults @"kBLE_PASSWORD_UserDefaults"
#define kBLE_identifier_UserDefaults @"kBLE_identifier_UserDefaults"
#define kBLE_Mac_UserDefaults @"kBLE_Mac_UserDefaults"
#define kBLE_IMEI_KEY @"kBLE_IMEI_KEY"

#define kLasetConnectedLocationLongtitude @"kLasetConnectedLocationLongtitude"
#define kLasetConnectedLocationLatitude @"kLasetConnectedLocationLatitude"
#define kLasetConnectedLocationTime @"kLasetConnectedLocationTime"
#define kNSUserDefaultsAntiLostSwitch @"kNSUserDefaultsAntiLostSwitch"



#define kWL_HEIGHT ((kScreenHeight >= 812) ? (kScreenHeight-88) : (kScreenHeight-64))

#endif /* CommonMacro_h */
