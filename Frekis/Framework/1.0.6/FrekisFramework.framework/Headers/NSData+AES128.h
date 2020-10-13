// Created by Noah
// http://noahmart.in

#import <Foundation/Foundation.h>

@interface NSData (AES128)

/**
 AES128 ECB 加密

 @param key 密钥
 @return 返回加密的数据
 */
- (NSData *)encryptWithKey:(NSData *)key;

/**
 AES128 ECB 解密

 @param key 密钥
 @return 返回解密后的数据
 */
- (NSData *)decryptWithKey:(NSData *)key;


/**
 AES128 ECB 加密
 
 @param key 密钥
 @return 返回加密的数据
 */
- (NSData *)encryptWithKey2:(NSData *)key;

/**
 AES128 ECB 解密
 
 @param key 密钥
 @return 返回解密后的数据
 */
- (NSData *)decryptWithKey2:(NSData *)key;

@end
