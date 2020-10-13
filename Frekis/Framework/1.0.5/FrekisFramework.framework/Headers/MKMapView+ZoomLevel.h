//
//  MKMapView+ZoomLevel.h
//  CENNTRO
//
//  Created by Andy on 2017/4/7.
//  Copyright © 2017年 Andy. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface MKMapView (ZoomLevel)

- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                  zoomLevel:(NSUInteger)zoomLevel
                   animated:(BOOL)animated;

@end
