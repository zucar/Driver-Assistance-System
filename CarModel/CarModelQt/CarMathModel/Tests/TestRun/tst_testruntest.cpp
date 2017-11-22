#include <QString>
#include <QtTest>
#include "kinematics.h"
#include "kinematicmodel.h"
class TestRunTest : public QObject
{
    Q_OBJECT

public:
    TestRunTest();

private Q_SLOTS:
    void testCase1();
};

TestRunTest::TestRunTest()
{
}

void TestRunTest::testCase1()
{
    int localDX = Path::KinematicModels::dX(5, 2.0 * 360 / 3.14);
    qDebug() << localDX;
    using namespace Path::KinematicModels;
    KinematicModel model;
    CarDescription desc;
    desc.setLength(5);
    desc.setDistLR(5);
    desc.setRadius(5);
    model.setCarDesc(&desc);
    model.setAngularVL(5);
    model.setAngularVR(5);
    qDebug() << model.longVelocity();
    QVERIFY2(model.longVelocity() == 25, "Not 25");

}

QTEST_MAIN(TestRunTest)

#include "tst_testruntest.moc"
