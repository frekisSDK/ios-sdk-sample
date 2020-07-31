//
//  WLBLEManagement.h
//  SolebeiSmartLock
//
//  Created by Andy on 2018/7/6.
//  Copyright © 2018年 FL SMART. All rights reserved.
//

#import "WLCommonTool.h"
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FMBLEModel.h"
#import "BLETools.h"
#import "FMDBManage.h"
#import "FMRecordModel.h"
#define kWLBLEUUID_Service @"FFE7"
#define kWLBLEUUID_ReadData @"FEC9"
#define kWLBLEUUID_WriteData @"FEC7"

// 服务UUID  可以指定
// 根据蓝牙通道来指定具体的值，蓝牙芯片不同，读取通道与特征值也会不同
static NSString *kReadServiceUUID = @"FEE7";
static NSString *kReadUUID = @"36F6";

static NSString *kWriteServiceUUID = @"FEE7";
static NSString *kWriteUUID = @"36F5";

// 这里根据需求来写，如果为空字符串则搜索全部蓝牙，如果不为空，则搜索含有此字符串的蓝牙名。
static NSString *kBLE_Name = @"";

typedef void(^WLBLEManagementScanBlock)(CBPeripheral *peripheral, FMBLEModel *fmBLEModel);
typedef void(^WLBLEManagementConnectingBlock)(CBPeripheral *peripheral);
typedef void(^WLBLEManagementConnectedBlock)(FMBLEModel *fmBLEModel);
typedef void(^WLBLEManagementUpdateValueBlock)(NSData *data, FMBLEModel *fmBLEModel);
typedef void(^WLBLEManagementUpdateUIBlock)(void);
typedef void(^WLBLEManagementUpdateBluethooth)(BOOL);
typedef void(^WLBLEManagementDisconnectedBlock)(CBPeripheral *peripheral);
typedef void(^WLBLEManagementPasswordChanged)(CBPeripheral *peripheral, FMBLEModel *fmBLEModel, BOOL);
typedef void(^WLBLEManagementLocked)(CBPeripheral *peripheral, FMBLEModel *fmBLEModel, BOOL);

@interface WLBLEManagement : NSObject

/**
 初始化单例
 
 @return self
 */
+ (instancetype)shareInstance;


/** state = yes, the bluetooth is on, state = no, the blutetooth is off */
@property (assign, nonatomic) BOOL state;

@property (strong, nonatomic) NSString *mac;
/** array */
@property (strong, nonatomic) NSMutableArray<FMBLEModel *> *bleArray;

/** WLBLEManagementUpdateBluethooth */
@property (copy, nonatomic) WLBLEManagementUpdateBluethooth bluethoothblock;
/** WLBLEManagementLocked */
@property (copy, nonatomic) WLBLEManagementLocked lockLocked;

/** WLBLEManagementLocked */
@property (copy, nonatomic) WLBLEManagementLocked lockUnlocked;

/** WLBLEManagementPasswordChanged */
@property (copy, nonatomic) WLBLEManagementPasswordChanged passwordChange;

/** WLBLEManagementConnectedBlock */
@property (copy, nonatomic) WLBLEManagementConnectedBlock connectedBlock;

/** WLBLEManagementUpdateValueBlock */
@property (copy, nonatomic) WLBLEManagementUpdateValueBlock updateValueBlock;


/** WLBLEManagementUpdateUIBlock */
@property (copy, nonatomic) WLBLEManagementUpdateUIBlock updateUIBlock;


/** WLBLEManagementDisconnectedBlock */
@property (copy, nonatomic) WLBLEManagementDisconnectedBlock disconnectedBlock;

- (void)scanBLEWithIsAutoScan:(BOOL)isAutoScan scanBlock:(WLBLEManagementScanBlock)scanBlock;


/** isAutoScan, if isAutoScan = NO, jump to scan vc to commit connect password. if isAutoScan = YES, auto connect and refresh UI */
@property (assign, nonatomic) BOOL isAutoScan;

- (void)stopScan;

/**
 当蓝牙重新打开的时候，开始重连当前存在的所有设备
 */
- (void)connectCurrentDevices;

/**
 当蓝牙被关闭的时候，更新当前蓝牙的状态信息，并保存到本地数据库
 */
- (void)updateCurrentDevices;
- (void)connectPeripheral:(CBPeripheral *)peripheral connecting:(WLBLEManagementConnectingBlock)connecting;
- (void)connectPeripheral:(CBPeripheral *)peripheral fmBLEModel:(FMBLEModel *)model;
- (void)disconnectPeripheral:(CBPeripheral *)peripheral;
- (void)logIt:(NSString *)string;

/** temp password */
@property (strong, nonatomic) NSString *tempPassword;
/** temp name */
@property (strong, nonatomic) NSString *tempName;

/**
 向设备发送数据
 
 @param writeCharacteristic 写入的特征值
 @param data 写入的数据
 @param peripheral 被写入的设备
 */
- (void)writeWithWriteCharacteristic:(CBCharacteristic *)writeCharacteristic data:(nonnull NSData *)data peripheral:(CBPeripheral *)peripheral;

@end
