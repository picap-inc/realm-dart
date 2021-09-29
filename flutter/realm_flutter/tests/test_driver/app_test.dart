// Imports the Flutter Driver API.
import 'package:flutter_driver/flutter_driver.dart';
import 'package:test/test.dart';
import 'const.dart';

void main(List<String> args) {
  group('Realm tests', () {
    FlutterDriver? driver;

    setUpAll(() async {
      driver = await FlutterDriver.connect();
    });

    tearDownAll(() async {
      await driver!.close();
    });

     // This single tests runs all Realm tests and reports test run failure if any Realm test fails. Contains all failed tests names.
     test('run all', () async {
      String result = await driver!.requestData(testCommand);
      if (result.isNotEmpty) {
        fail('Failed tests: $result');
      }
    });
  });
}