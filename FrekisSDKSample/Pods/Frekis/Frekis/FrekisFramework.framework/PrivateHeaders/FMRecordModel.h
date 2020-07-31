//
//  FMRecordModel.h
//  SolebeiSmartLock
//
//  Created by Andy on 2018/5/31.
//  Copyright © 2018年 FL SMART. All rights reserved.
//

#import "BaseModel.h"

@interface FMRecordModel : BaseModel

/** ble id */
@property (strong, nonatomic) NSString *identifier_ID;
/** time */
@property (strong, nonatomic) NSString *time;
/** operation id */
@property (assign, nonatomic) NSInteger operationId;
/** mac string */
@property (strong, nonatomic) NSString *mac;
/** name  */
@property (strong, nonatomic) NSString *bleName;

+ (NSString *)operationContentWithOperationId:(NSInteger)operationId;

@end
