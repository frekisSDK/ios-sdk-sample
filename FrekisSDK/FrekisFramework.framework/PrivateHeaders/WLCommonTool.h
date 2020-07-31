//
//  WLLocationTool.h
//  工具类，实现的功能请查看函数名说明
//
//  Created by Andy on 2017/3/1.
//  Copyright © 2017年 Andy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <MapKit/MapKit.h>
#import "LPPopup.h"

#define kWLCommonTool [WLCommonTool shareLocationTool]

@class WLCommonTool;

typedef void(^WLLocationToolStopLocationBlock)(WLCommonTool *locationTool);

@interface WLCommonTool : NSObject

+ (instancetype)shareLocationTool;


#pragma mark - 与定位相关的
- (void)starLocation:(CLLocationDistance)distance;
- (void)stopLocation;
/** stop location block */
@property (copy, nonatomic) WLLocationToolStopLocationBlock stopLocationBlock;
// address dictionary properties
@property (nonatomic, copy, nullable) NSString *name; // eg. Apple Inc.
@property (nonatomic, copy, nullable) NSString *thoroughfare; // street name, eg. Infinite Loop
@property (nonatomic, copy, nullable) NSString *subThoroughfare; // eg. 1
@property (nonatomic, copy, nullable) NSString *locality; // city, eg. Cupertino
@property (nonatomic, copy, nullable) NSString *subLocality; // neighborhood, common name, eg. Mission District
@property (nonatomic, copy, nullable) NSString *administrativeArea; // state, eg. CA
@property (nonatomic, copy, nullable) NSString *subAdministrativeArea; // county, eg. Santa Clara
@property (nonatomic, copy, nullable) NSString *postalCode; // zip code, eg. 95014
@property (nonatomic, copy, nullable) NSString *ISOcountryCode; // eg. US
@property (nonatomic, copy, nullable) NSString *country; // eg. United States
@property (nonatomic, copy, nullable) NSString *inlandWater; // eg. Lake Tahoe
@property (nonatomic, copy, nullable) NSString *ocean; // eg. Pacific Ocean
@property(nonatomic) CLLocationCoordinate2D coordinate;

#pragma mark - 震动
- (void)vibrate;

/**
 检查邮箱格式
 
 @param email 邮箱
 @return 正确=yes，错误=no
 */
- (BOOL)checkEmailAddressFormat:(nonnull NSString *)email;

/**
 *  弹出提示信息的方法
 *
 *  @param string 需要显示的内容
 */
- (void)showMessage:(NSString *_Nullable)string;

/**
 判断是否有中文
 
 @param str 字符串
 @return yes or no
 */
- (BOOL)checkChinese:(NSString *_Nullable)str;

/**
 在前台不静音播放文字，否则震动
 
 @param content 需要播放的内容
 */
- (void)speakUtteranceWithContent:(nonnull NSString *)content;

- (void)playWithName:(NSString *)str ofType:(NSString *)type;
- (void)cancelPlayWithName:(NSString *)str ofType:(NSString *)type;

/**
 百度地图坐标转高德地图坐标
 */
CLLocationCoordinate2D MKMapCoordinateConvertBaiDuToAMap(double bd_lat, double bd_lon);


/**
 显示提醒，如果在APP界面提醒，在后台则通知

 @param title 标题
 */
- (void)showMessageWithTitle:(NSString *)title;

/**
 本地推送消息
 
 @param title 消息内容
 */
- (void)showMessageWithBackModelTitle:(NSString *)title;

/**
 获取手机当前的时间

 @return 返回当前的时间，格式是：YYYY-MM-dd HH:mm:ss
 */
- (NSString *)getCurrentTime;

/**
 16进制字符串转成data
 
 @param str 16进制字符串
 @return data
 */
- (NSData *)convertHexStrToData:(NSString *)str;

#pragma mark - 地图坐标系转换
/*
 * 百度坐标系(BD-09)  转  WGS坐标
 */
+(CLLocationCoordinate2D)wgs84frombd09:(CLLocationCoordinate2D)bd09Coord;
/*
 * WGS坐标  转   百度坐标系(BD-09)
 */
+(CLLocationCoordinate2D)bd09fromwgs84:(CLLocationCoordinate2D)wgs84Coord;
/*
 * 百度坐标系(BD-09)  转  火星坐标系(GCJ-02)
 */
+(CLLocationCoordinate2D)gcj02frombd09:(CLLocationCoordinate2D)bd09Coord;
/*
 * 火星坐标系(GCJ-02)  转   百度坐标系(BD-09)
 */
+(CLLocationCoordinate2D)bd09fromgcj02:(CLLocationCoordinate2D)gcj02Coord;
/*
 * GCJ02(火星坐标系)  转  WGS84坐标
 */
+(CLLocationCoordinate2D)wgs84fromgcj02:(CLLocationCoordinate2D)gcj02Coord;
/*
 * WGS84坐标  转  GCJ02(火星坐标系)
 */
+(CLLocationCoordinate2D)gcj02fromwgs84:(CLLocationCoordinate2D)wgs84Coord;
/*
 * WGS84坐标  转  GCJ02(火星坐标系)
 */
+(CLLocationCoordinate2D)transformFromWGSToGCJ:(CLLocationCoordinate2D)wgsLoc;

////////////////////

/*
 * 地球坐标系 (WGS-84) -> 火星坐标系 (GCJ-02)
 */
+ (CLLocationCoordinate2D)wgs2gcj:(CLLocationCoordinate2D) coordinate;

/*
 * 地球坐标系 (WGS-84) <- 火星坐标系 (GCJ-02)
 */
+ (CLLocationCoordinate2D)gcj2wgs:(CLLocationCoordinate2D)coordinate;

////////////////////


/**
 * 开始到结束的时间差
 */
+ (int)dateTimeDifferenceWithStartTime:(NSString *)startTime endTime:(NSString *)endTime;

#pragma mark - 计算转向角度

#define RadToDeg 57.2957795130823228646477218717336654663086 //180.f / M_PI
#define DegToRad 0.0174532925199432954743716805978692718782 // M_PI / 180.f

+ (CLLocationDirection)calculateCourseFromMapPoint:(MKMapPoint)point1 to:(MKMapPoint)point2;

+ (CLLocationDirection)calculateCourseFromCoordinate:(CLLocationCoordinate2D)coord1 to:(CLLocationCoordinate2D)coord2;
+ (CLLocationDirection)fixNewDirection:(CLLocationDirection)newDir basedOnOldDirection:(CLLocationDirection)oldDir;

- (CLLocationCoordinate2D)getUserLocatioin;

@end
