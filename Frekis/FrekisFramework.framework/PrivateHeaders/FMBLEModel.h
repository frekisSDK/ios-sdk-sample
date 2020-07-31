//
//  FMBLEModel.h
//  SolebeiSmartLock
//
//  Created by Andy on 2018/5/31.
//  Copyright © 2018年 FL SMART. All rights reserved.
//

#import "BaseModel.h"

#import <CoreBluetooth/CoreBluetooth.h>

@interface FMBLEModel : BaseModel

/** ble id */
@property (strong, nonatomic) NSString *identifier_ID;
/** name  */
@property (strong, nonatomic) NSString  *bleName;
/** password */
@property (strong, nonatomic) NSString *password;
/** battery */
@property (assign, nonatomic) NSInteger battery;
/** lock state: unlocked 0/  1 locked/ */
@property (assign, nonatomic) NSInteger lockState;
/** auto unlock switch */
@property (assign, nonatomic) BOOL isAutoUnlock;
/** Vibration alert switch */
@property (assign, nonatomic) BOOL isVibrationAlert;
/** notification switch */
@property (assign, nonatomic) BOOL isNotification;
/** consign model switch 托运模式 */
@property (assign, nonatomic) BOOL isConsignModel;
/** mac string */
@property (strong, nonatomic) NSString *mac;
/** connection state */
@property (assign, nonatomic) BOOL isConnected;


/** Read */
@property (strong, nonatomic) CBCharacteristic *readCharacteristic;
/** Write */
@property (strong, nonatomic) CBCharacteristic *writeCharacteristic;

@property (strong, nonatomic) NSData *tokenData;

/** ble device object */
@property (strong, nonatomic) CBPeripheral *peripheral;


@end
