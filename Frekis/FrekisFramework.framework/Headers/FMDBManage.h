//
//  FMDBManage.h
//
//

#import <Foundation/Foundation.h>

#define kFMDBManage [FMDBManage shareIntance]

@class FMBLEModel, FMRecordModel;

@interface FMDBManage : NSObject

+(FMDBManage *)shareIntance;

#pragma mark -
#pragma mark FMBLEModel


/**
 插入新设备

 @param bleModel 设备模型
 @return 是否插入成功
 */
- (BOOL)insertFMBLEModel:(FMBLEModel *)bleModel;

/**
 查询某个设备
 
 @param identifier 设备id
 @return 有就返回此设备模型，没有就返回nil
 */
- (FMBLEModel *)selectFMBLEModelWithIdentifier:(NSString *)identifier;

/**
 查询某个设备
 
 @param mac 设备mac地址
 @return 有就返回此设备模型，没有就返回nil
 */
- (FMBLEModel *)selectFMBLEModelWithMac:(NSString *)mac;

/**
 更新某个设备

 @param bleModel 需要被更新的设备
 @return 是否更新成功
 */
- (BOOL)updateFMBLEModel:(FMBLEModel *)bleModel;

/**
 更新某个设备
 
 @param bleModel 需要被更新的设备
 @return 是否更新成功
 */
- (BOOL)updateFMBLEModelForMac:(FMBLEModel *)bleModel;

/**
 删除设备

 @param identifier 设备ID
 @return 是否删除成功
 */
- (BOOL)deleteFMBLEModel:(NSString *)identifier;

/**
 删除设备
 
 @param mac 设备ID
 @return 是否删除成功
 */
- (BOOL)deleteFMBLEModelWithMac:(NSString *)mac;

/**
 删除所有的设备

 @return 是否删除成功
 */
- (BOOL)deleteAllFMBLEModel;

/**
 查询所有设备

 @return 设备列表
 */
- (NSArray<FMBLEModel *> *)allFMBLEModel;





#pragma mark FMRecordModel

/**
 新增操作记录
 
 @param recordModel 操作记录模型数据
 @return 是否新增成功
 */
- (BOOL)insertFMRecordModel:(FMRecordModel *)recordModel;

/**
 查询某个设备下面的某一个操作记录
 
 @param recordIdentifier 操作记录ID
 @param bleMac 设备ID
 @return 返回查询的操作记录，没有就返回nil
 */
- (FMRecordModel *)selectFMRecordModelWithRecordIdentifier:(NSString *)recordIdentifier bleMac:(NSString *)bleMac;

/**
 更新某个操作记录的数据
 
 @param recordModel 需要更新的操作记录数据
 @return 是否更新成功
 */
- (BOOL)updateFMRecordModel:(FMRecordModel *)recordModel;

/**
 删除某个设备下面的某一个操作记录
 
 @param recordIdentifier 操作记录ID
 @param bleMac 设备ID
 @return shanc
 */
- (BOOL)deleteFMRecordModelWithRecordIdentifier:(NSString *)recordIdentifier bleMac:(NSString *)bleMac;
/**
 删除所有的操作记录
 
 @return 是否删除成功
 */
- (BOOL)deleteAllFMrecordModels;

/**
 查询某个设备下面的所有操作记录
 
 @param bleMac 设备ID
 @return 返回查询的操作记录模型数组，没有就返回nil
 */
- (NSArray *)allFMRecordModelWithbleModel:(NSString *)bleMac;
/**
 查询整个数据库的所有操作记录
 
 @return 返回整个数据库的所有操作记录
 */
- (NSArray *)allFMRecordModel;

@end
