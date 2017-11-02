#include <QString>
#include <QtTest>
#include "kinematics.h"
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
    int localDX = Path::KinematicModel::dX(5, 2.0 * 360 / 3.14);
    qDebug() << localDX;

}

QTEST_MAIN(TestRunTest)

#include "tst_testruntest.moc"
